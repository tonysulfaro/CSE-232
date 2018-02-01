#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<cmath>
#include<string>
using std::to_string; using std::string;

string abIndex_friend(long ab_numerator, long ab_denominator, long f_pair){
    return to_string(ab_numerator) + "/" + to_string(ab_denominator) +
           ":" + to_string(f_pair);
}

//return divisor sum
long divisor_sum(long number){

    long i = 0;
    long sum = 0;

    while(i <= number){

        i++;
        if(number%i == 0){
            sum += i;
        }
    }
    return sum;
}

//returns greatest common divisor
long gcd(long first_num, long second_num){

    long greatest_divisor = 0;

    for(int i = 0; i <= first_num+second_num; i++){

        i++;
        if(first_num%i == 0 and second_num%i ==0){

            greatest_divisor = i;
        }
    }
    return greatest_divisor;
}

//if arguments and divisor sum have their gcd 1
bool is_solidary(long number){

    bool condition = false; //initialized to be false

    return condition;
}

//checks limits
long friendly_check(long integrer_number, long upper_limit){

    long adbIndex = 0;

    return adbIndex;
}

//adds up all the divisors of a number
int main (){
    cout << boolalpha;   // print true or false for bools
    int test;
    cin >> test;
    switch (test) {
        case 1 : {   // divisor sum test
            long input;
            cin >> input;
            cout << divisor_sum(input) << endl;
            break;
        } // of case 1

        case 2:{    // gcd test
            long first, second;
            cin >> first >> second;
            cout << gcd(first, second) << endl;
            break;
        } // of case 2

        case 3: {    // is_solitary test
            long input;
            cin >> input;
            cout << is_solitary(input) << endl;
            break;
        } // of case 3

        case 4: {
            // friend check. Make sure the return value is the
            // result of calling abIndex_friend, a string!
            long input, limit;
            cin >> input >> limit;
            cout << friendly_check(input, limit) << endl;
            break;
        } // of case 4

    } // of switch
} // of main