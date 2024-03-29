#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *parent, *successor;

	if (root == NULL)
		return (NULL);

	node = bst_search(root, value);
	if (node == NULL)
		return (root);

	parent = node->parent;

	if (node->left == NULL && node->right == NULL)
	{
		if (parent == NULL)
			root = NULL;
		else if (parent->left == node)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(node);
	}
	else if (node->left == NULL || node->right == NULL)
	{
		if (parent == NULL)
		{
			root = (node->left != NULL) ? node->left : node->right;
			root->parent = NULL;
		}
		else if (parent->left == node)
		{
			parent->left = (node->left != NULL) ? node->left : node->right;
			parent->left->parent = parent;
		}
		else
		{
			parent->right = (node->left != NULL) ? node->left : node->right;
			parent->right->parent = parent;
		}
		free(node);
	}
	else
	{
		successor = node->right;
		while (successor->left != NULL)
			successor = successor->left;

		node->n = successor->n;
		root->right = avl_remove(root->right, successor->n);
	}

	return (binary_tree_balance(root));
}
