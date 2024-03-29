/* 120-binary_tree_is_avl.c */
#include "binary_trees.h"
#include <limits.h>

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value the node can have
 * @max: Maximum value the node can have
 *
 * Return: 1 if the tree is a valid AVL tree, and 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, diff;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	diff = left_height - right_height;
	if (diff < -1 || diff > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
