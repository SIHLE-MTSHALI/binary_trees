#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	tree = build_avl(array, 0, size - 1, NULL);

	return (tree);
}

/**
 * build_avl - Builds an AVL tree from a sorted array recursively
 * @array: Pointer to the first element of the array to be converted
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @parent: Pointer to the parent node of the current node
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *root;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}
