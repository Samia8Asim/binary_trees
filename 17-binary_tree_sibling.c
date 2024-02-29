#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: input tree node
 * Return: return a pointer to the sibling node and null otherwiae
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
