#include "binary_trees.h"

/**
 * enqueue - Adds a binary tree node to the end of a queue
 * @head: Double pointer to the head of the queue
 * @node: The binary tree node to add to the queue
 * Description: Adds a new node to a queue for level-order traversal.
 */

void enqueue(queue_t **head, const binary_tree_t *node);
const binary_tree_t *dequeue(queue_t **head);

void enqueue(queue_t **head, const binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *last = *head;

	new_node->node = node;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

/**
 * dequeue - Removes and returns the first element from a queue
 * @head: Double pointer to the head of the queue
 * Return: The binary tree node removed from the queue
 * Description: Removes front node from a queue used in level-order traversal.
 */

const binary_tree_t *dequeue(queue_t **head)
{
	if (head == NULL || *head == NULL)
		return (NULL);

	queue_t *temp = *head;
	const binary_tree_t *node = temp->node;
	*head = (*head)->next;

	free(temp);

	return (node);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 * Description: Performs level-order traversal on a binary tree.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	enqueue(&queue, tree);

	while ((current = dequeue(&queue)) != NULL)
	{
		func(current->n);
		if (current->left != NULL)
			enqueue(&queue, current->left);
		if (current->right != NULL)
			enqueue(&queue, current->right);
	}
}
