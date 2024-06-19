#include "all_headers.h"
#include <stdio.h>

int main() {
    LinkedList *list = create_linked_list();
    if (list == NULL) {
        return 1; // Exit if list creation failed
    }

    insert_at_head(list, 10);
    insert_at_head(list, 20);
    insert_at_head(list, 30);

    print_linked_list(list);
    delete_linked_list(list);

    return 0;
}