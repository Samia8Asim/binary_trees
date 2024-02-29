#include "binary_trees.h"

/**
 * binary_tree_depth - the depth of a node in a binary tree
 * @tree: Pointer to the node
 *
 * Return: Depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dep = 0;

	if (!tree)
		return (0);

	while (!tree->parent)
	{
		dep++;
		tree = tree->parent;
	}

	return (dep);
}
