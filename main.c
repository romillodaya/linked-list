#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.c"
#include "slist.h"

void test_empty_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list) == 0); 
}

void test_add_at_head(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert (slist_length(list) == 0);
    list = slist_addnode_head(list, 10);
    assert(slist_length(list) == 1);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert(slist_length(list) == 3);
    assert(slist_lookup(list,20) == 1);
}

void test_add_at_tail(){
    Slist s1=slist_new();
    Slist *list=&s1;
    assert (slist_length(list) ==0);
    list=slist_addnode_tail(list,10);
    assert(slist_length(list)==1);
    list=slist_addnode_head(list,20);
    list=slist_addnode_head(list,30);
    assert(slist_length(list)==3);

}


void test_delnode_head(){
    Slist s1=slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list,10);
    list=slist_addnode_head(list,20);
    list=slist_addnode_head(list,30);
    list=slist_delnode_head(list);
    assert(slist_length(list)==2);
    assert(slist_lookup(list,30)==0);
    assert(slist_lookup(list,20)==1);
    list=slist_addnode_tail(list,40);
    list=slist_addnode_head(list,50);
    assert(slist_length(list)==4);
}


void test_delnode_tail(){
    Slist s1=slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list,10);
    list=slist_addnode_tail(list,20);
    list=slist_addnode_tail(list,30);
    list=slist_delnode_tail(list);
    assert(slist_length(list)==2);
    assert(slist_lookup(list,30)==0);
    assert(slist_lookup(list,20)==1);
    list = slist_delnode_tail(list);
    assert(slist_length(list)==1);
}



int main(){
    test_empty_list();
    test_add_at_head();
    test_delnode_head();
    test_delnode_tail();
    return 0;
}  