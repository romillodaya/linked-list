#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.c"

void test_empty_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list) == 0); 
}

int main(){
    test_empty_list();
    return 0;
}  