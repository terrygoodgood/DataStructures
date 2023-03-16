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

    /// Test for queue
    tests::Queue::TestAll();

    /// TODO : Test for vector
    tests::Vector::TestVector();
    return 0;
}
