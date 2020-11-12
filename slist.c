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