#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct node_t
{
    struct node_t* next;
    void* data;
} node_t;


typedef struct linkedlist_t
{
    struct node_t* head;
} linkedlist_t;

linkedlist_t* linkedlist_new();
void linkedlist_add(linkedlist_t *restrict, void*);
int linkedlist_remove(linkedlist_t *restrict, const void*);
unsigned int linkedlist_size(const linkedlist_t*);
void linkedlist_destroy(linkedlist_t*);
node_t* linkedlist_last(const linkedlist_t*);


void** linkedlist_to_array(const linkedlist_t*);
void linkedlist_destroy_array(void**);


node_t** linkedlist_to_node_array(const linkedlist_t*);
void linkedlist_destroy_node_array(node_t**);

#endif
