/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:49:14 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 14:18:14 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : stack
Expected files   : stack.c
Allowed functions: malloc free
--------------------------------------------------------------------------------

Implement a stack data structure in C, using the following structures in your
code:

	struct s_node {
		void          *content;
		struct s_node *next;
	};

	struct s_stack {
		struct s_node *top;
	};


A stack uses LIFO (last-in fist-out) ordering :
the most recent item added to the stack is the first item to be removed.

Implement 5 functions for the following stack operations :

	- init() : Initialize the stack.
	  The top pointer is set to NULL.

	- pop(stack) : Remove the top item from the stack and return it.
	  If the stack is empty, the function returns NULL.

	- push(stack, item) : Add an item to the top of the stack.

	- peek(stack) : Return the top of the stack.
	  If the stack is empty, the function returns NULL.

	- isEmpty(stack) : Return 1 if the stack is empty, 0 otherwise.


These functions must be declared as follows:

	struct s_stack *init(void);

	void *pop(struct s_stack *stack);

	void push(struct s_stack *stack, void *content);

	void *peek(struct s_stack *stack);

	int isEmpty(struct s_stack *stack);
 */
#include <stdlib.h>

struct          s_node {
        void    *content;
		struct  s_node *next;
};

struct          s_stack {
	struct      s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack	*stack;
	
	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	void	*tmp;

	if (!stack || !stack->top)
		return (NULL);
	tmp = stack->top->content;
	stack->top = stack->top->next;
	return (tmp);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new;

	if (!stack)
		return ;
	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

/*Remove before submiting */
/*#include <stdio.h>
int		main()
{
	struct s_stack		*stack;
	void				*node;
	stack = NULL;
	
	printf("isEmpty = %d\n", isEmpty(stack));
	
	printf("init\n");
	stack = init();
	printf("push (1)\n");
	push(stack, "1");
	printf("isEmpty = %d peek = %s\n", isEmpty(stack), (char *)peek(stack));
	printf("push (2)\n");
	push(stack, "2");
	printf("isEmpty = %d peek = %s\n", isEmpty(stack), (char *)peek(stack));
	printf("push (3)\n");
	push(stack, "3");
	printf("isEmpty = %d peek = %s\n", isEmpty(stack), (char *)peek(stack));
	printf("pop\n");
	node = pop(stack);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(stack), (char *)peek(stack), (char *)node);
	printf("pop\n");
	node = pop(stack);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(stack), (char *)peek(stack), (char *)node);
	printf("pop\n");
	node = pop(stack);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(stack), (char *)peek(stack), (char *)node);
}
*/
