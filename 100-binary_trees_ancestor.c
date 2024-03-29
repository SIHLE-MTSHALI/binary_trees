#include "binary_trees.h"

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node
 * @ancestor: Pointer to the potential ancestor node
 * @node: Pointer to the node to check
 *
 * Return: 1 if @ancestor is an ancestor of @node, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node)
{
	if (ancestor == NULL || node == NULL)
		return (0);

	if (ancestor == node)
		return (1);

	return (binary_tree_is_ancestor(ancestor->left, node) ||
			binary_tree_is_ancestor(ancestor->right, node));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ancestor = (binary_tree_t *)first;
	while (ancestor != NULL)
	{
		if (binary_tree_is_ancestor(ancestor, second))
			return (ancestor);
		ancestor = ancestor->parent;
	}

	return (binary_trees_ancestor(first->parent, second));
}
