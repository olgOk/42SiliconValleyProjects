# 42-Project-Wolf3d

This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever.
It will help to explore ray-casting. The goal of the project is to make a dynamic view inside a maze,
in which a user has to find its way.
A Wolfeinstein-like renderer made in C using minilibX, with textures, basic map files, and a simple game menu.

![wolf3d](/img/wolf3d_1.png)
![wolf3d](/img/wolf3d_2.png)

### Contents
* [About the Project](#About-the-Project)
* [Features](#Features)
* [How to use](#How-to-use)
* [Creating your own map](#Creating_your_own_map)

### About the Project
-------------------------
This project is aimed to get understanding of the technique used to create ray casting 3D scenes. 
The main technique covered is similar to the one used by [IdSoftware][1] in the Wolfenstein 3D source code. 
The main part of the project is to understand the mathematics used for ray casting,
and implement a full-featured projected environment using C programming language.

The Project has been done as a team project consisting of two students:
1. [Kirill Naumov][2]
2. [Olga Okrut][3] 


### Features
-----------------
* 3D Wall Projections
* 2D Map and Player Movement
* Wall textures, ceiling texture
* Handling of arrow key events: player's rotation left and right, move forward and back 
* Game menu implementation
* Background music

### How to use
-------------------
Download or git clone the project folders.

Run `make` and you're set.

Run `./wolf3d [map_file]`, a window should appear.

In a game menu select `PLAY` to start playing.

You can navigate through the map using the arrow keys. To exit game press `ESC` button,
from the game navigation menu select `EXIT`.

Select `MUSIC: ON OFF` to mute/unmute music while playing.

### Creating your own map
---------------------------------
It's very easy to create your own game map. Open a file in your favorite text editor,
make sure you have a grid of integers (each one being it's block ID),
and it should work right out of the box. Spawns at the center of the map.

```1 1 1 1 1
   1 0 2 0 1
   1 0 0 0 1
   1 1 1 1 1
   ```


[1]: https://www.idsoftware.com/en-us
[2]: https://github.com/KirillVNaumov
[3]: https://github.com/olgOk
