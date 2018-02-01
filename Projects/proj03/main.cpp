#include<iostream>
#include<algorithm>
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

    //return std::__gcd(first_num, second_num); //found out there was a function in the algorithm library
                                            // for this but I have my own code down below
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
bool is_solitary(long number){

    long number_gcd = gcd(number, number);
    long number_divisor_sum = divisor_sum(number);

    return (number_gcd == number and number_divisor_sum == 1);
}

//checks limits
string friendly_check(long number, long upper_limit){

    long numer = divisor_sum(number);
    //long denom = number;
    long other_numer = 0;
    long other_denom = 0;

    long test = 0;

    //this works just have to reduce the fraction after it is done
    for(int i = 0; i <= upper_limit; i++){

        long temp_numer = divisor_sum(i);
        long temp_denom = i;
        if(temp_denom == number and temp_numer == numer){
            other_numer = temp_numer;
            other_denom = temp_denom;
        }
    }

    return abIndex_friend(numer, number, test);
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
