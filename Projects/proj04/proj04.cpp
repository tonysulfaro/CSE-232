#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<cmath>

const string the_chars = "0123456789abcdefghijklmnopqrstuvwxyz";

//functions

//reverses string
string reverse_str(string s){

    //s = reverse(s.begin(),s.end());
    string s_reversed;;

    for(int i = s.size(); i != -1; i--){
        for(auto chr: the_chars){
            if(chr == s[i]){
                s_reversed += s[i];
            }
        }
    }
    return s_reversed;
}

//checks if is palindrome
bool is_palindrome(string s){

    string reverse_string = reverse_str(s);

    return reverse_string == s;
}

//converts provided long to a string where string represents the long converted to the provided base.
string long_to_base(long number, long base){

    if(base == 10){ //normal numbers
        string output;

        while(number != 0){
            long remain = number % 10;
            output += the_chars[remain];
            number /= 10;
        }
        return reverse_str(output);
    }
    else if(base == 2){ //binary
        string output;

        while(number != 0){
            long remain = number % 2;
            output += the_chars[remain];
            number /= 2;
        }
        return reverse_str(output);
    }
    else if(base == 16){ //hexadecimal
        string output;

        while(number != 0){
            long remain = number % 16;
            output += the_chars[remain];
            number /= 16;
        }
        return reverse_str(output);
    }
    return "Invalid Expression";
}

//checks if number is prime
bool is_prime(long number){

    for(int i = 2; i < number; i++){
        //sees if any other number other than itself and 1 is a divisor
        if(number%i == 0){
            return false;
        }
    }
    return true;
}

//determine if the long argument is both prime and a palindrome in one of three bases: binary, decimal or hexadecimal
string is_pal_prime(long number){

    string s = "one of following 4 strings binary-pal-prime o decimal-pal-prime o hex-pal-prime o not-pal-prime";

    //get diff bases for numbers
    string number_hex = long_to_base(number, 16);
    string number_binary = long_to_base(number, 2);

    //check if is prime
    bool decimal_prime = is_prime(number);
    //bool binary_prime = is_prime(long(number_binary));

    //check if is palindrome
    bool decimal_pal = is_palindrome(to_string(number));
    bool binary_pal = is_palindrome(number_binary);
    bool hex_pal = is_palindrome(number_hex);

    /*
    if(binary_pal and binary_prime){
        return "binary-pal-prime";
    }*/
    if(decimal_prime and decimal_pal){
        return "decimal-pal-prime";
    }
    else if(binary_pal and decimal_prime){
        return "binary-pal-prime";
    }
    else if(hex_pal and decimal_prime){
        return "hex-pal-prime";
    }

    return "not-pal-prime";
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
    cout << reverse_str(input);
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
