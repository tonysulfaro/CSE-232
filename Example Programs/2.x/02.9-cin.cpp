#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::skipws;
using std::noskipws;

int main (){
  char C;
  int i;
  
  cout << "enter integers"<<endl;
  cin >> i;
  while (!cin.fail()){
    cout <<"Got int:"<< i <<endl;
    cin >> i;
  }

  cin.clear();
  cin.ignore(80, '\n');

  cout << "enter characters"<<endl;

  while (cin >> C)
    cout <<"Got char:"<<C<<", ";
}
