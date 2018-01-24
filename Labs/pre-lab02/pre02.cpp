#include<iostream>
using std::cout; using std::endl; using std::cin;

int main (){
 long long_1, long_2;
 cin >> long_1 >> long_2;

long result_1 = 1;

if (long_1 > long_2)
 result_1 = 100;
 else
 result_1 = 200;
 cout << result_1 << endl; // Line 1

long result_2 = 1;
 long result_3 = 1;
 if (long_1 < long_2){
 result_2 = long_1 / long_2;
 result_3 = long_1 % long_2;
 }
 else if (long_1 == long_2)
 result_2++;
 else
 --result_2;
 cout << result_2 << endl; // Line 2
 cout << result_3 << endl; // Line 3

long cnt = 0;
 long result_4 = 1;
 long result_5 = 1;
 while (cnt < long_1){
 result_4 += 1;
 result_5 *= 2;
 ++cnt;
 }
 cout << cnt << endl; // Line 4
 cout << result_4 << endl; // Line 5
 cout << result_5 <<endl; // Line 6

long i;
 long result_6 = 1;
 long result_7 = 1;
 for(i=0; i<long_1; ++i){
 result_6 = 1 + result_6 * 2;
 result_7 = result_7 % 6;
 }
 cout << i << endl; // Line 7
 cout << result_6 << endl;// Line 8
 cout << result_7 << endl;// Line 9
}
