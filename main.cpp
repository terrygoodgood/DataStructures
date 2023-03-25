#include <iostream>
#include "tests.h"
using namespace std;

int main()
{
    cout << "=====================" << endl;
    cout << "   Data  Structure   " << endl;
    cout << "=====================" << endl;

    /// Test for linkedlist
    tests::LinkedList::TestAll();

    /// Test for stack
    tests::Stack::TestAll();

    /// Test for queue
    tests::Queue::TestAll();

    /// Test for vector
    tests::Vector::TestAll();

    /// TODO : Test for tree
    return 0;
}
