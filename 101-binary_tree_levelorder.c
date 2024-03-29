#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Enqueues a node into the queue
 * @queue: Pointer to the queue
 * @rear: Pointer to the rear index of the queue
 * @size: Pointer to the size of the queue
 * @node: Node to enqueue
 *
 * Return: Pointer to the updated queue. Dynamically adjusts the size of
 * the queue to accommodate new nodes.
 */
binary_tree_t **enqueue(binary_tree_t **queue, size_t *rear, size_t *size,
			binary_tree_t *node)
{
	binary_tree_t **new_queue = NULL;

	if (*rear == *size)
	{
		*size += 10;
		new_queue = realloc(queue, sizeof(binary_tree_t *) * (*size));
		if (new_queue == NULL)
		{
			free(queue);
			exit(1);
		}
		queue = new_queue;
	}

	queue[*rear] = node;
	(*rear)++;

	return (queue);
}

/**
 * binary_tree_levelorder - Performs a level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The function applies
 * a specific operation to the node value.
 * Description: This funct traverses a binary tree in level-order and applies
 * the function pointed to by func to each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL;
	size_t front = 0, rear = 0, size = 0;
	binary_tree_t *node = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = enqueue(queue, &rear, &size, (binary_tree_t *)tree);
	while (front < size)
	{
		node = queue[front];
		func(node->n);

		if (node->left != NULL)
			queue = enqueue(queue, &rear, &size, node->left);
		if (node->right != NULL)
			queue = enqueue(queue, &rear, &size, node->right);

		front++;
	}

	free(queue);
}
