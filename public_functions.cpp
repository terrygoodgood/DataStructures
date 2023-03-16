
#include "public_functions.h"
#include <iostream>
using namespace std;


/*
    cout << "\033[1;31mHello, world!\033[0m" << endl; // Red color
    cout << "\033[1;32mHello, world!\033[0m" << endl; // Green color
    cout << "\033[1;33mHello, world!\033[0m" << endl; // Yellow color
    cout << "\033[1;34mHello, world!\033[0m" << endl; // Blue color
    cout << "\033[1;35mHello, world!\033[0m" << endl; // Magenta color
    cout << "\033[1;36mHello, world!\033[0m" << endl; // Cyan color
    cout << "\033[1;37mHello, world!\033[0m" << endl; // White color
*/
void ErrorPrint(string s){
    cout << endl << "\033[1;31m[  ERROR ]  " << s << "\033[0m" << endl;
}

void TestPassPrint(string s){
    cout << endl << "\033[1;32m[ PASSED ]  " << s << "\033[0m" << endl;
}

void TestPrint(string s){
    cout << endl << "\033[1;36m[  TEST  ]  " << s << "\033[0m" << endl;
}
