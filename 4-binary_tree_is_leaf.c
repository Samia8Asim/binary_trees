#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function to checks if a node is a leaf
 * @node: Pointer to the node to check if it's node
 *
 * Return: one or 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (!node)
        return (0);

    return (node->left == NULL && node->right == NULL);
}
