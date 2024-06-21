#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

BinarySearchTree* create_bst() {
    BinarySearchTree *tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

TreeNode* create_node(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bst_insert(BinarySearchTree *tree, int data) {
    TreeNode *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }

    TreeNode *parent = NULL;
    TreeNode *current = tree->root;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    new_node->parent = parent;
    if (parent == NULL) {
        tree->root = new_node;
    } else if (data < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

void bst_transplant(BinarySearchTree *tree, TreeNode *u, TreeNode *v) {
    if (u->parent == NULL) { // u is the root
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

TreeNode* bst_find_min(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* bst_find_max(TreeNode *node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

// The successor of a node x is the node with the smallest key greater than x.key
TreeNode* bst_successor(TreeNode *node) {
    if (node->right != NULL) {
        return bst_find_min(node->right);
    } else {
        TreeNode *parent = node->parent;
        while (parent != NULL && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

void bst_remove(BinarySearchTree *tree, int data) {
    TreeNode *node = bst_search(tree, data);
    if (node == NULL) {
        return;
    }

    if (node->left == NULL) {
        bst_transplant(tree, node, node->right);
    } else if (node->right == NULL) {
        bst_transplant(tree, node, node->left);
    } else { // node to remove has two children
        TreeNode *successor = bst_find_min(node->right);
        if (successor->parent != node) {
            bst_transplant(tree, successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        bst_transplant(tree, node, successor);
        successor->left = node->left;
        successor->left->parent = successor;
    }
    free(node);
}

TreeNode* bst_search(const BinarySearchTree *tree, int data) {
    TreeNode *current = tree->root;
    while (current != NULL && current->data != data) {
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

void bst_print(const TreeNode *node) {
    // inorder tree walk
    if (node != NULL) {
        bst_print(node->left);
        printf("%d ", node->data);
        bst_print(node->right);
    }
}

void bst_destroy_subtree(TreeNode *node) {
    if (node != NULL) {
        bst_destroy_subtree(node->left);
        bst_destroy_subtree(node->right);
        free(node);
    }
}

void bst_destroy(BinarySearchTree *tree) {
    if (tree != NULL) {
        bst_destroy_subtree(tree->root);
        free(tree);
    }
}