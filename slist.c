#include <stdlib.h>
#include <assert.h>
#include "slist.h"

Slist       slist_new() {
    Slist s1 = {NULL, NULL, 0};
    return s1;
}

uint32_t    slist_length(const Slist *list){
    assert (list != NULL);
    return list->length;
}

static Node* _get_new_node_(int32_t val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

Slist       slist_addnode_head(Slist *list, int32_t val){
    assert (list != NULL);
    Node *new_node = _get_new_node_(val);
    new_node->next = list->head;
    list->head = new_node;
    if(list->tail == NULL){
        list->tail = new_node;
    }
    ++list->length;
    assert((list->length == 1) && (list->head == list->tail) ||
           (list->length > 1 ) && (list->head != list->tail)
          );
}