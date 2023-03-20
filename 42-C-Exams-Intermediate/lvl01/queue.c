/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:56:57 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 17:26:30 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : queue
Expected files   : queue.c
Allowed functions: malloc free
--------------------------------------------------------------------------------

Implement a queue data structure in C, using the following structures in your 
code:

	struct s_node {
		void *content;
		struct s_node *next;
	};

	struct s_queue {
		struct s_node *first;
		struct s_node *last;
	};


A queue uses FIFO (first-in fist-out) ordering:
	Items are removed from the data structure in the same order that they are added.

Implement 5 functions for the following queue operations:

	- init() : Initialize the queue.
	  The first and last pointers are set to NULL.

	- enqueue(queue, item) : Add an item to the end of the queue.

	- dequeue(queue) : Remove the first item from the queue and return it.
	  If the queue is empty, the function returns NULL.

	- peek(queue) : Return the first item of the queue.
	  If the queue is empty, the function returns NULL.

	- isEmpty(queue) : Return 1 if the queue is empty, 0 otherwise.


These functions must be declared as follows:

	struct s_queue *init(void);

	void enqueue(struct s_queue *queue, void *content);

	void *dequeue(struct s_queue *queue);

	void *peek(struct s_queue *queue);

	int isEmpty(struct s_queue *queue); */
    
#include <stdlib.h>

struct              s_node {
    void            *content;
    struct s_node   *next;
};

struct                  s_queue 
{
    struct  s_node      *first;
    struct  s_node      *last;
};

struct s_queue *init(void)
{
    struct s_queue  *queue;

    queue = (struct s_queue *)malloc(sizeof(struct s_queue));
    queue->first = NULL;
    queue->last = NULL;
    return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
    struct s_node   *new;

    if (!queue)
        return ;
    new = (struct s_node *)malloc(sizeof(struct s_node));
    new->content = content;
    new->next = NULL;
    if (!queue->last)
    {
        queue->last = new;
        queue->first = new;
        return ;
    }
    queue->last->next = new;
    queue->last = new;

}

void *dequeue(struct s_queue *queue)
{
    void    *tmp;

    if (!queue || !queue->first)
        return (NULL);
    tmp = queue->first->content;
    queue->first = queue->first->next;
    if (!queue->first)
        queue->last = NULL;
    return (tmp);
}

void *peek(struct s_queue *queue)
{
    if (!queue || !queue->first)
        return (NULL);
    return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
    if (!queue || (!queue->first && !queue->last))
        return (1);
    return (0);
    
}


/*For testing. Remove before submiting*/
#include <stdio.h>
void    print_queue(struct s_queue *queue)
{
    struct s_node *tmp;
    if (!queue)
    {
        printf("Queue doesn't exist\n");
        return ;
    }
    tmp = queue->first;
    while (tmp)
    {
        printf("[%s]->", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");
}
int		main()
{
	struct s_queue		*queue;
	void				*content;
	queue = NULL;
	
	printf("isEmpty = %d\n", isEmpty(queue));
    print_queue(queue);
	printf("init\n");
	queue = init();
	printf("push (1)\n");
	enqueue(queue, "1");
	printf("isEmpty = %d peek = %s\n", isEmpty(queue), (char *)peek(queue));
    print_queue(queue);
	printf("push (2)\n");
	enqueue(queue, "2");
	printf("isEmpty = %d peek = %s\n", isEmpty(queue), (char *)peek(queue));
    print_queue(queue);
	printf("push (3)\n");
	enqueue(queue, "3");
	printf("isEmpty = %d peek = %s\n", isEmpty(queue), (char *)peek(queue));
    print_queue(queue);
	printf("\npop\n");
	content = dequeue(queue);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(queue), (char *)peek(queue), (char *)content);
    print_queue(queue);
	printf("pop\n");
	content = dequeue(queue);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(queue), (char *)peek(queue), (char *)content);
    print_queue(queue);
	printf("pop\n");
	content = dequeue(queue);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(queue), (char *)peek(queue), (char *)content);
    print_queue(queue);
}
