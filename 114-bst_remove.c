#include "binary_trees.h"
#include <stdlib.h>

bst_t *bst_find_min(bst_t *root);

/**
 * bst_remove - Removes a node from a BST
 * @root: pointer to the root node of the tree
 * @value: value to remove from the tree
 * Return: pointer to the new root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * bst_find_min - Finds the minimum value node in a BST
 * @root: pointer to the root node of the tree
 * Return: pointer to the node with minimum value
 */
bst_t *bst_find_min(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

