#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t nodes = binary_tree_size(tree);

	return (binary_tree_is_perfect_util(tree, height, 0, nodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect_util - function to check if binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @height: Height of the tree
 * @level: Current level being checked
 * @nodes: Number of nodes in the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect_util(
	const binary_tree_t *tree, size_t height, size_t level, size_t nodes)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (height == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_util(tree->left, height, level + 1, nodes) &&
		binary_tree_is_perfect_util(tree->right, height, level + 1, nodes));
}
