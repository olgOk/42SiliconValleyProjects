# -*- coding: utf-8 -*-
"""My Environment.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1uYhy2zyovorxvs61TqOKv-hJOFPnvs-B
"""

# Commented out IPython magic to ensure Python compatibility.
# Note: If you haven't installed the following dependencies, run:
!apt-get install -y xvfb
!pip install 'gym==0.10.11'
!pip install 'imageio==2.4.0'
!pip install PILLOW
!pip install 'pyglet==1.3.2'
!pip install pyvirtualdisplay
!pip install tf-agents-nightly
try:
#   %%tensorflow_version 2.x
except:
  pass

#import all requered frameworks

from __future__ import absolute_import, division, print_function

import abc
import tensorflow as tf
import numpy as np
import base64
import matplotlib.pyplot as plt

from tf_agents.agents.dqn import dqn_agent
from tf_agents.drivers import dynamic_step_driver
from tf_agents.environments import py_environment
from tf_agents.environments import tf_environment
from tf_agents.environments import tf_py_environment
from tf_agents.environments import utils
from tf_agents.specs import array_spec
from tf_agents.environments import wrappers
from tf_agents.environments import suite_gym
from tf_agents.trajectories import time_step as ts
from tf_agents.eval import metric_utils
from tf_agents.metrics import tf_metrics
from tf_agents.networks import q_network
from tf_agents.replay_buffers import tf_uniform_replay_buffer
from tf_agents.trajectories import trajectory
from tf_agents.utils import common

tf.compat.v1.enable_v2_behavior()

"""Python environments have a step(action) -> next_time_step method that applies an action to the environment, and returns the following information about the next step:
observation: This is the part of the environment state that the agent can observe to choose its actions at the next step.
reward: The agent is learning to maximize the sum of these rewards across multiple steps.
step_type: Interactions with the environment are usually part of a sequence/episode. e.g. multiple moves in a game of chess. step_type can be either FIRST, MID or LAST to indicate whether this time step is the first, intermediate or last step in a sequence.
discount: This is a float representing how much to weight the reward at the next time step relative to the reward at the current time step.
These are grouped into a named tuple TimeStep(step_type, reward, discount, observation).
The interface that all python environments must implement is in environments/py_environment.PyEnvironment.
"""

#Define Hyperparameters

num_iterations = 20000 # @param {type:"integer"}

initial_collect_steps = 1000  # @param {type:"integer"} 
collect_steps_per_iteration = 1  # @param {type:"integer"}
replay_buffer_max_length = 100000  # @param {type:"integer"}

batch_size = 64  # @param {type:"integer"}
learning_rate = 1e-3  # @param {type:"number"}
log_interval = 200  # @param {type:"integer"}

num_eval_episodes = 10  # @param {type:"integer"}
eval_interval = 1000  # @param {type:"integer"}

#define my environment class

class MyBoard(py_environment.PyEnvironment):

  """
    Create a custom environment
    Actions: go [up, down, left, right]
                [0,  1,    2,    3   ]
    Observations: value at the current state
    Reward: -1 if step outside the grid, +1 if step between any cells except
            from cell [0,1] to [1,1] where reward defined as +5
  """
  def __init__(self):
    #define action to choosee from: minimum set to 0 and maximum set to 3
    self._action_spec = array_spec.BoundedArraySpec(
        shape=(), dtype=np.int32, minimum=0, maximum=3, name='action')
    
    #define observation
    self._observation_spec = array_spec.BoundedArraySpec(
        shape=(2,), dtype=np.int32, minimum=[0,0], maximum=[1,2], name='observation')
    
    #define the initial state
    self._state = [0, 0]
    self._reward = 0.0
    self._episode_ended = False

  #return the current action
  def action_spec(self):
    return self._action_spec

  def observation_spec(self):
    return self._observation_spec

  #reset the initial state
  #The environment is mutable, so we need a function that restores
  #the initial state. According to the PyEnvironment documentation
  #such a function must be called _reset, and it must return the state
  # of the environment and information that it is the first step of
  # the simulation. A valid response is created by calling ts.restart
  # with the current state as an argument.
  def _reset(self):
    self._state = [0, 0]
    self._episode_ended = False
    return ts.restart(np.array(self._state, dtype=np.int32))

  def move(self, action):
    row,col = self._state[0], self._state[1]
    if action == 0: #up
      if row - 1 >= 0:
        self._state[0] -= 1
        return 1
    elif action == 1: #down
      if row + 1 <= 1:
        self._state[0] += 1
        if (self._state[0] == 1 and self._state[1] == 1):
          return 5
        return 1
    elif action == 2: #left
      if col - 1 >= 0:
        self._state[1] -= 1
        return 1
    elif action == 3: #right
      if col + 1 <= 2:
        self._state[1] += 1
        return 1
    self._episode_ended = True
    return -1

  def if_in_grid(self):
    if (self._state[0] < 0 or self._state[0] > 1 or 
        self._state[1] < 0 or self._state[1] > 2):
      return 0
    return 1

  # a function which takes action and returns the reward.
  # We must override the _step function defined in the PyEnvironment class.
  # First of all, if the game has ended the step function must call the reset function.
  def _step(self, action):
    # The last action ended the episode. Ignore the current action and start
    # a new episode.
    if self._episode_ended:
      return self.reset()

    #make a movement in the grid
    self._reward += self.move(action)

    
    if self._episode_ended:
      return ts.termination(np.array(self._state, dtype=np.int32), self._reward)
    else:
      return ts.transition(
                np.array(self._state, dtype=np.int32), reward=0, discount=0.9)

# When the environment is ready, it is best to call the validate_py_environment
# function. It helps to spot silly mistakes, such as uninitialized variables
# or incompatible data types.

env = MyBoard()
utils.validate_py_environment(env, episodes=5)

# Given `time_step`: TimeStep(step_type=array(0, dtype=int32), reward=array(0., dtype=float32), discount=array(1., dtype=float32), observation=array([[0, 0]], dtype=int32))
# `time_step_spec`: TimeStep(step_type=ArraySpec(shape=(), dtype=dtype('int32'), name='step_type'), reward=ArraySpec(shape=(), dtype=dtype('float32'), name='reward'), discount=BoundedArraySpec(shape=(), dtype=dtype('float32'), name='discount', minimum=0.0, maximum=1.0), observation=BoundedArraySpec(shape=(2,), dtype=dtype('int32'), name='observation', minimum=[0 0], maximum=[1 2]))

#Convert python environment to TF environment

tf_env = tf_py_environment.TFPyEnvironment(env)
print(isinstance(tf_env, tf_environment.TFEnvironment))
print("TimeStep Specs:", tf_env.time_step_spec())
print("Action Specs:", tf_env.action_spec())

#Usually two environments are instantiated:
# one for training and one for evaluation.

# First we will load the Gridworld environments 
# into a TimeLimit Wrapper which terminates the game 
# if 10 steps are reached. 
# The results are then wrapped in the TF environment handlers.


train_py_env = wrappers.TimeLimit(env, duration=100) #change duration later if neded
eval_py_env = wrappers.TimeLimit(env, duration=100)

train_env = tf_py_environment.TFPyEnvironment(train_py_env)
eval_env = tf_py_environment.TFPyEnvironment(eval_py_env)

"""The DQN agent can be used in any environment which has a discrete action space.
At the heart of a DQN Agent is a QNetwork, a neural network model that can learn to predict QValues (expected returns) for all actions, given an observation from the environment.
Use tf_agents.networks.q_network to create a QNetwork, passing in the observation_spec, action_spec, and a tuple describing the number and size of the model's hidden layers.
"""

# Next, setup an agent, a learning model, replay buffer, driver.
# Connect them together

#right now, creating a network with single hidden layer of 100 nodes
fc_layer_params = (100,)

q_net = q_network.QNetwork(
    train_env.observation_spec(),
    train_env.action_spec(),
    fc_layer_params=fc_layer_params)

#using Adam optimizer
optimizer = tf.compat.v1.train.AdamOptimizer(learning_rate=learning_rate)

#a variable to keep track of how many times the network was updated.
train_step_counter = tf.compat.v2.Variable(0)

#define the agent
tf_agent = dqn_agent.DqnAgent(
    train_env.time_step_spec(),
    train_env.action_spec(),
    q_network=q_net,
    optimizer=optimizer,
    td_errors_loss_fn=common.element_wise_squared_loss,
    train_step_counter=train_step_counter)

tf_agent.initialize()

"""Define Policies"""

eval_policy = tf_agent.policy
collect_policy = tf_agent.collect_policy

#random policies

random_policy = random_tf_policy.RandomTFPolicy(train_env.time_step_spec(),
                                                train_env.action_spec())

"""Next, create the replay buffer and replay observer. 

The replay buffer is used to contain the observation and action pairs so they can be used for training.
"""

"""
  PARAMETERS:
    data_spec: the shape of a row that is contained in the buffer
    batch_size: represents the size of the batch that is saved in the replay buffer
    max_length: represents how many records the buffer can hold before starting
                overwrite the oldest ones with the newest entries.
"""

replay_buffer = tf_uniform_replay_buffer.TFUniformReplayBuffer(
    data_spec=tf_agent.collect_data_spec,
    batch_size=train_env.batch_size,
    max_length=replay_buffer_max_length)

replay_observer = [replay_buffer.add_batch]

"""Create a dataset out of the replay buffer that we can iterate through and train the agent."""

def collect_step(environment, policy):
    time_step = environment.current_time_step()
    action_step = policy.action(time_step)
    next_time_step = environment.step(action_step.action)
    traj = trajectory.from_transition(time_step, action_step, next_time_step)

    # Add trajectory to the replay buffer
    replay_buffer.add_batch(traj)

def collect_data(env, policy, buffer, steps):
  for _ in range(steps):
    collect_step(env, policy, buffer)

collect_data(train_env, random_policy, replay_buffer, steps=100)

"""
  PARAMETERS:
    num_parallel_calls: the number of items to process in paralell
    sample_batch_size: the number of items to pass to the Neural Network for training
    num_steps: specifies the number of consecutive items to return as sub batches
               in the returned batch. This is extremely important for episodic
               games where shuffling all the data will cause the data to be corrupted. 
               The minimum value here is 2 because then we will receive sub batches 
               of [observation-action,new_observation-action] for training. 
               This would be another variable that can be adjusted.
"""

dataset = replay_buffer.as_dataset(
            num_parallel_calls=3,
            sample_batch_size=batch_size,
    num_steps=2).prefetch(3)
    
iterator = iter(dataset)
print(iterator)

"""Create the driver which will simulate the agent in the game and store the state, action, reward pairs in the replay buffer, and keep track of some metrics."""

train_metrics = [
            tf_metrics.NumberOfEpisodes(),
            tf_metrics.EnvironmentSteps(),
            tf_metrics.AverageReturnMetric(),
            tf_metrics.AverageEpisodeLengthMetric(),
]

driver = dynamic_step_driver.DynamicStepDriver(
            train_env,
            collect_policy,
            observers=replay_observer + train_metrics,
    num_steps=1)

"""Metrics and Evaluation"""

def compute_avg_return(environment, policy, num_episodes=10):

  total_return = 0.0
  for _ in range(num_episodes):

    time_step = environment.reset()
    episode_return = 0.0

    while not time_step.is_last():
      action_step = policy.action(time_step)
      time_step = environment.step(action_step.action)
      episode_return += time_step.reward
    total_return += episode_return

  avg_return = total_return / num_episodes
  return avg_return.numpy()[0]

episode_len = []

final_time_step, policy_state = driver.run()

# Reset the train step
agent.train_step_counter.assign(0)

avg_return = compute_avg_return(eval_env, tf_agent.policy, num_eval_episodes)
returns = [avg_return]

for i in range(num_iterations):
  for _ in range(collect_steps_per_iteration):
    collect_step(train_env, tf_agent.collect_policy)

  final_time_step, _ = driver.run(final_time_step, policy_state)
  experience, _ = next(iterator)
  train_loss = tf_agent.train(experience=experience)
  step = tf_agent.train_step_counter.numpy()

  if step % log_interval == 0:
      print('step = {0}: loss = {1}'.format(step, train_loss.loss))
      episode_len.append(train_metrics[3].result().numpy())
      print('Average episode length: {}'.format(train_metrics[3].result().numpy()))

  if step % eval_interval == 0:
      avg_return = compute_avg_return(eval_env, tf_agent.policy, num_eval_episodes)
      print('step = {0}: Average Return = {1}'.format(step, avg_return))
      returns.append(avg_return)
plt.plot(episode_len)
plt.show()

iterations = range(0, num_iterations + 1, eval_interval)
plt.plot(iterations, returns)
plt.ylabel('Average Return')
plt.xlabel('Iterations')
