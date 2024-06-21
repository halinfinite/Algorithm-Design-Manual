#include "all_headers.h"
#include <stdio.h>

// Helper function to print a message indicating whether a test passed or failed
void print_test_result(int test_num, int condition) {
    if (condition) {
        printf("Test %d passed.\n", test_num);
    } else {
        printf("Test %d failed.\n", test_num);
    }
}

int main() {
    // LinkedList *list = create_linked_list();
    // if (list == NULL) {
    //     return 1; // Exit if list creation failed
    // }

    // insert_at_head(list, 10);
    // insert_at_head(list, 20);
    // insert_at_head(list, 30);

    // print_linked_list(list);
    // delete_linked_list(list);

    // Stack* stack = create_stack();
    // push(stack, 10);
    // push(stack, 20);
    // push(stack, 30);

    // printf("Top element: %d\n", stack_peek(stack)); // Should print 30

    // printf("Popped element: %d\n", pop(stack)); // Should print 30
    // printf("Popped element: %d\n", pop(stack)); // Should print 20

    // printf("Is stack empty? %d\n", stack_is_empty(stack)); // Should print 0 (false)

    // printf("Popped element: %d\n", pop(stack)); // Should print 10
    // printf("Is stack empty? %d\n", stack_is_empty(stack)); // Should print 1 (true)

    // // Try popping from empty stack
    // printf("Popped element: %d\n", pop(stack)); // Should print error message and -1
    
    // Queue *queue = create_queue();
    // enqueue(queue, 10);
    // enqueue(queue, 20);
    // enqueue(queue, 30);

    // printf("Peek: %d\n", queue_peek(queue)); // Should print 10

    // printf("Dequeue: %d\n", dequeue(queue)); // Should print 10
    // printf("Dequeue: %d\n", dequeue(queue)); // Should print 20
    // printf("Dequeue: %d\n", dequeue(queue)); // Should print 30

    // if (queue_is_empty(queue)) {
    //     printf("Queue is empty\n"); // Should print this
    // }

    BinarySearchTree *tree = create_bst();

    // Test 1: Insert elements into the BST and print the tree
    bst_insert(tree, 50);
    bst_insert(tree, 30);
    bst_insert(tree, 70);
    bst_insert(tree, 20);
    bst_insert(tree, 40);
    bst_insert(tree, 60);
    bst_insert(tree, 80);
    printf("BST after inserts: ");
    bst_print(tree->root);
    printf("\n");
    // printf("%d\n", tree->root->data);
    // printf("%d\n", tree->root->left->data);
    // printf("%d\n", tree->root->left->right->data);


    // Test 2: Search for existing and non-existing elements
    TreeNode *node = bst_search(tree, 40);
    print_test_result(2, node != NULL && node->data == 40);

    node = bst_search(tree, 100);
    print_test_result(3, node == NULL);

    // Test 3: Find minimum and maximum values
    node = bst_find_min(tree->root);
    print_test_result(4, node != NULL && node->data == 20);

    node = bst_find_max(tree->root);
    print_test_result(5, node != NULL && node->data == 80);

    // Test 4: Remove elements and print the tree
    bst_remove(tree, 20); // Removing a leaf node
    printf("BST after removing 20: ");
    bst_print(tree->root);
    printf("\n");

    bst_remove(tree, 30); // Removing a node with one child
    printf("BST after removing 30: ");
    bst_print(tree->root);
    printf("\n");

    bst_remove(tree, 50); // Removing a node with two children
    printf("BST after removing 50: ");
    bst_print(tree->root);
    printf("\n");

    // Test 5: Remove non-existing element
    bst_remove(tree, 100); // Should not alter the tree
    printf("BST after attempting to remove 100: ");
    bst_print(tree->root);
    printf("\n");

    // Test 6: Delete the entire tree
    bst_destroy(tree);

    printf("All tests completed.\n");

    return 0;
}