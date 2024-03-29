/* 100-binary_trees_ancestor.c */
#include "binary_trees.h"

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
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ancestor = first;
	while (ancestor != NULL)
	{
		if (binary_tree_is_ancestor(second, ancestor))
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	return (binary_trees_ancestor(first->parent, second));
}

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node
 * @node: Pointer to the possible ancestor node
 * @target: Pointer to the target node
 *
 * Return: 1 if node is an ancestor of target, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *node,
		const binary_tree_t *target)
{
	if (node == NULL || target == NULL)
		return (0);

	if (node == target)
		return (1);

	return (binary_tree_is_ancestor(node->left, target) ||
			binary_tree_is_ancestor(node->right, target));
}
