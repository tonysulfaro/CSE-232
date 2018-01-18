#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
int main (){
    long long_1=0;
    long long_2;

    cout << long_1 << endl;     // Line 1
    cout << long_2 << endl;     // Line 2

    cout << long_1++ << endl;   // Line 3
    cout << long_1 << endl;     // Line 4
    cout << ++long_1 << endl;   // Line 5
    cout << long_1 << endl;     // Line 6

    long_1 = 10;
    long_1 += 2;
    cout << long_1 << endl;     // Line 7
    long_1 *= 2;
    cout << long_1 << endl;     // Line 8

    cout << (long_2 = 3) << endl; // Line 9
    cout << (long_2 == 3) << endl;// Line 10
    cout << boolalpha;
    cout << (long_2 == 3) << endl; // Line 11

    long_1 = 1;
    long_2 = 2;
    cout << long_1 / long_2 << endl;    // Line 12
    cout << long_1 % long_2 << endl;   // Line 13

    (long_1 = 100) || (long_2 = 200);
    cout << long_1 << endl;         // Line 14
    cout << long_2 << endl;         // Line 15

    (long_1 = 0) && (long_2 = 200);
    cout << long_1 << endl;          // Line 16
    cout << long_2 << endl;          // Line 17
}