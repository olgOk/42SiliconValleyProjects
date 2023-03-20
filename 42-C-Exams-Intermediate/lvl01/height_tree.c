/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:10:27 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 17:43:52 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : height_tree
Expected files   : height_tree.c
Allowed functions: 
--------------------------------------------------------------------------------

Implement a function to calculate the height of an n-ary tree.

Your should use the following node structure in your code for the n-ary tree:

	struct s_node {
		int           value;
		struct s_node **nodes;
	};

In this struct nodes is a null-terminated array.

Note that the height of a tree is the number of EDGES on the longest path from
the root node to a leaf. A tree with a single node will have a height of 0.

An empty tree should have height -1;

The function must be declared as follows:

	int height_tree(struct s_node *root);

EXAMPLE:

The Input Tree :

	        94
           / \
          /   \
         34   52
        / \	    \
       /   \	 \
      1    99	 11
		 /
		/
	    13
Output : 3 */

struct      s_node {
	int     value;
	struct  s_node **nodes;
};

void    calculate_height(struct s_node *root, int *max_height, int index_height)
{
    int i = 0;

    if (index_height > *max_height)
        *max_height = index_height;
    if (!root->nodes)
        return ;
    while (root->nodes[i])
    {
        calculate_height(root->nodes[i], max_height, index_height + 1);
        ++i;
    }
}

int height_tree(struct s_node *root)
{
    int height = 0;

    if (!root)
        return (-1);
    calculate_height(root, &height, 0);
    return (height);
}