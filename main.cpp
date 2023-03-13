#include <iostream>

#include "tests.h"


#include <vector>


using namespace std;

int main()
{
    cout << "=====================" << endl;
    cout << "   Data  Structure   " << endl;
    cout << "=====================" << endl;

    /// Test for linkedlists
    tests::LinkedList::TestLinkedlist();
    tests::LinkedList::TestDoublyLinkedList();
    tests::LinkedList::TestCircularlyLinkedLists();

    /// Test for stack
    tests::Stack::TestArrayBasedStack();
    tests::Stack::TestLinkedListBasedStack();

    /// TODO : Test for queue

    return 0;
}
