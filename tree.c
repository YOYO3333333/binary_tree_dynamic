#include <stdio.h>

#include "binary_tree.h"

int size(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    return 1 + size(tree->right) + size(tree->left);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return -1;
    return 1 + max(height(tree->right), height(tree->left));
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    printf("%d ", tree->data);
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
    return;
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    dfs_print_infix(tree->left);
    printf("%d ", tree->data);
    dfs_print_infix(tree->right);
    return;
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    dfs_print_postfix(tree->left);
    dfs_print_postfix(tree->right);
    printf("%d ", tree->data);
    return;
}

int is_perfect(const struct binary_tree *tree)
{
    int cut = size(tree);
    int high = height(tree);
    int p = 1;
    int i = 0;
    while (i <= high)
    {
        p *= 2;
        i++;
    }
    if (cut == (p - 1))
        return 1;
    return 0;
}

int is_complex_pro(const struct binary_tree *tree, int index, int size)
{
    if (tree == NULL)
        return 1;
    if (index >= size)
        return 0;
    if (is_complex_pro(tree->left, 2 * index + 1, size))
    {
        if (is_complex_pro(tree->right, 2 * index + 2, size))
            return 1;
    }
    return 0;
}

int is_complete(const struct binary_tree *tree)
{
    int len = size(tree);
    return is_complex_pro(tree, 0, len);
}

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if (tree->left == NULL || tree->right == NULL)
    {
        if (is_degenerate(tree->left) && is_degenerate(tree->right))
            return 1;
    }
    return 0;
}

int is_full(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if ((tree->left == NULL) && (tree->right == NULL))
        return 1;
    if ((tree->left != NULL) && (tree->right != NULL))
    {
        if ((is_full(tree->left)) && (is_full(tree->right)))
            return 1;
    }
    return 0;
}

int is_bst_pro(const struct binary_tree *tree, int in, int s)
{
    if (tree == NULL)
        return 1;
    if ((tree->data >= in) && (tree->data < s))
    {
        if ((is_bst_pro(tree->left, in, tree->data))
            && (is_bst_pro(tree->right, tree->data, s)))
            return 1;
    }
    return 0;
}

int is_bst(const struct binary_tree *tree)
{
    int in = -2147483648;
    int s = 2147483647;
    return is_bst_pro(tree, in, s);
}
