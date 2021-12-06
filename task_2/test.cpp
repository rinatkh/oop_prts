#include <iostream>
#include "duolinkedlist.h"

void test() {
    DuoLinkedList<int> list;
    list.push_back(7);
    list.push_back(5);
    list.push_back(8);
    list.push_back(6);
    list.show();
    list.sort();
    list.show();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
}

int main() {
    test();
    return 0;
}