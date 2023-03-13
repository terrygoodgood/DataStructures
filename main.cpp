#include <iostream>

#include "tests.h"


#include <vector>


using namespace std;

int main()
{
    cout << "=====================" << endl;
    cout << "   Data  Structure   " << endl;
    cout << "=====================" << endl;

    tests::LinkedList::TestLinkedlist();
    tests::LinkedList::TestDoublyLinkedList();
    tests::LinkedList::TestCircularlyLinkedLists();

    tests::Stack::TestArrayBasedStack();
    tests::Stack::TestLinkedListBasedStack();
    return 0;
}
