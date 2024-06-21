#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct TreeNode {
    int data;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinarySearchTree {
    TreeNode *root;
} BinarySearchTree;

// Function declarations
BinarySearchTree* create_bst();
TreeNode* create_node(int data);
void bst_insert(BinarySearchTree *tree, int data);
void bst_transplant(BinarySearchTree *tree, TreeNode *u, TreeNode *v);
void bst_remove(BinarySearchTree *tree, int data);
void bst_print(const TreeNode *node);
TreeNode* bst_search(const BinarySearchTree *tree, int data);
TreeNode* bst_find_min(TreeNode *node);
TreeNode* bst_find_max(TreeNode *node);
TreeNode* bst_successor(TreeNode *node);
void bst_destroy_subtree(TreeNode *node);
void bst_destroy(BinarySearchTree *tree);

#endif // BINARY_SEARCH_TREE_H