#include <stdlib.h>
#include <stdbool.h>
#include "include/linkedlist.h"

linkedlist_t* linkedlist_new() {
    linkedlist_t* list = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    list->head = NULL;
    return list;
}

unsigned int linkedlist_size(const linkedlist_t* ll) {
    unsigned int size = 0;
    node_t* item = ll->head;

    while (item != NULL) {
        item = item->next;
        size++;
    }

    return size;
}

node_t* linkedlist_last(const linkedlist_t* ll) {
    node_t* last = NULL;
    node_t* item = ll->head;

    while (item != NULL) {
        last = item;
        item = item->next;
    }

    return last;
}

void linkedlist_add(linkedlist_t *restrict linkedlist, void* item) {
    node_t* last = linkedlist_last(linkedlist);

    node_t* new = (node_t*)malloc(sizeof(node_t));

    new->data = item;
    new->next = NULL;

    if (last == NULL) {
        linkedlist->head = new;
        return;
    }

    last->next = new;

}


void** linkedlist_to_array(const linkedlist_t* ll) {
    unsigned int size = linkedlist_size(ll);

    void** array = (void**)malloc(sizeof(void*) * size);

    node_t* item = ll->head;
    unsigned int i = 0;

    while (item != NULL) {
        array[i] = item->data;
        item = item->next;
        i++;
    }

    return array;

}

void linkedlist_destroy_array(void ** array) {
    free(array);
}

node_t** linkedlist_to_node_array(const linkedlist_t* ll) {
    unsigned int size = linkedlist_size(ll);

    node_t** array = (node_t**)malloc(sizeof(node_t*) * size);

    node_t* item = ll->head;
    unsigned int i = 0;

    while (item != NULL) {
        array[i] = item;
        item = item->next;
        i++;
    }

    return array;

}

void linkedlist_destroy_node_array(node_t ** array) {
    free(array);
}

void linkedlist_destroy(linkedlist_t *ll) {
    node_t** items = linkedlist_to_node_array(ll);

    for (unsigned int i = 0; i < linkedlist_size(ll); i++) {
        free(items[i]);
    }

    linkedlist_destroy_node_array(items);

    free(ll);

}

int linkedlist_remove(linkedlist_t *restrict ll, const void *target) {
    node_t** array = linkedlist_to_node_array(ll);

    unsigned int targetIndex = 0;
    bool found = false;

    for (unsigned int i = 0; i < linkedlist_size(ll); i++) {
        if (array[i]->data == target) {
            found = true;
            targetIndex = i;
            break;
        }
    }

    if (!found) {
        linkedlist_destroy_node_array(array);
        return 1;
    }

    if (targetIndex == 0) {
    
        if (linkedlist_size(ll) == 1) {
            ll->head = NULL;
        } else {
            ll->head = array[1];
        }
        
    } else {

        if (targetIndex + 1 > linkedlist_size(ll)) {
            ll->head = NULL;
        } else {
            array[targetIndex - 1]->next = array[targetIndex + 1];
        }

    }

    free(array[targetIndex]);

    linkedlist_destroy_node_array(array);

    return 0;
}
