#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<cmath>

const string the_chars = "0123456789abcdef";

//functions

//reverses string
string reverse_str(string s){

    return s;
}

//checks if is palindrome
bool is_palindrome(string s){

    return true;
}

//converts provided long to a string where string represents the long converted to the provided base.
string long_to_base(long convert, long base){

    string s = "test";

    return s;
}

//checks if number is prime
bool is_prime(long number){

    return true;
}

//determine if the long argument is both prime and a palindrome in one of three bases: binary, decimal or hexadecimal
string is_pal_prime(long number){

    string s = "one of following 4 strings binary-pal-prime
                o decimal-pal-prime
                o hex-pal-prime
                o not-pal-prime";

    return s;
}

//main method
int main (){
  long test_num;
  cin >> test_num;
  cout << boolalpha;

  switch(test_num) {

  case 1: {
    string input;
    cin >> input;
    cout << reverse_string(input);
    break;
  }

  case 2:{
    string input;
    cin >> input;
    cout << is_palindrome(input);
    break;
  }

  case 3:{
    long n, base;
    cin >> n >> base;
    cout << long_to_base(n,base);
    break;
  }

  case 4:{
    long n;
    cin >> n;
    cout << is_prime(n);
    break;
  }

  case 5:{
    long n;
    cin >> n;
    cout << is_pal_prime(n);
    break;
  }

  } // of switch
}  // of main
