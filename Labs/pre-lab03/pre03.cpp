#include<iostream>
using std::cout; using std::endl; using std::cin;
using std::boolalpha;

int main (){
    cout << boolalpha;
    long my_long_1 = 123;
    long &my_long_2 = my_long_1;
    long *my_long_3 = &my_long_1;

    cout << my_long_1 << endl; // Line 1
    cout << my_long_2 << endl; // Line 2
    cout << my_long_3 << endl; // Line 3
    cout << *my_long_3 << endl; // Line 4
    cout << (&my_long_1 == my_long_3) << endl; // Line 5

    my_long_2 = 456;

    cout << my_long_1 << endl; // Line 6
    cout << my_long_2 << endl; // Line 7
    cout << my_long_3 << endl; // Line 8
    cout << *my_long_3 << endl; // Line 9
    cout << (&my_long_1 == my_long_3) << endl; // Line 10

    *my_long_3 = 789;
    cout << my_long_1 << endl; // Line 11
    cout << my_long_2 << endl; // Line 12
    cout << my_long_3 << endl; // Line 13
    cout << *my_long_3 << endl; // Line 14
    cout << (&my_long_1 == my_long_3) << endl; // Line 15

    long another_long = 012;
    my_long_3 = &another_long;

    cout << my_long_1 << endl; // Line 16
    cout << my_long_2 << endl; // Line 17
    cout << my_long_3 << endl; // Line 18
    cout << *my_long_3 << endl; // Line 19
    cout << (&my_long_1 == my_long_3) << endl; // Line 20
}
