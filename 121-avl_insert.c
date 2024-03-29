/* 121-avl_insert.c */
#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
			*tree = binary_tree_balance(*tree);
			return (new_node);
		}
		return (avl_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
			*tree = binary_tree_balance(*tree);
			return (new_node);
		}
		return (avl_insert(&((*tree)->right), value));
	}
	return (NULL);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;
	if (new_root->right != NULL)
		new_root->right->parent = tree;
	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
