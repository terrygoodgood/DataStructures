#include <iostream>
#include "tests.h"

using namespace std;

int main()
{
    cout << "=====================" << endl;
    cout << "   Data  Structure   " << endl;
    cout << "=====================" << endl;

    /// Test for linkedlists
    tests::LinkedList::TestAll();

    /// Test for stack
    tests::Stack::TestAll();

    /// TODO : Test for queue
    tests::Queue::TestArrayQueue();
    return 0;
}
