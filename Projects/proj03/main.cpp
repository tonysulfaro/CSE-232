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


    long sum = 0;
    long i = 0;

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

    while ( second_num != 0) {
        long r = first_num % second_num;
        first_num = second_num;
        second_num = r;
    }
    return first_num;
}

//if arguments and divisor sum have their gcd 1
bool is_solitary(long number){

    long gcd_div_sum = gcd(divisor_sum(number),number);

    return (gcd_div_sum == 1);
}

//checks limits
string friendly_check(long number, long upper_limit){

    long numerator = divisor_sum(number);
    long denominator = number;
    long pair_value = 0;
    long n = 2;

    //reduce numerator and denominator
    for (int i = denominator * numerator; i > 1; i--) {
        if ((denominator % i == 0) && (numerator % i == 0)) {
            denominator /= i;
            numerator /= i;
        }
    }

    //this works just have to reduce the fraction after it is done
    while(n <= upper_limit){

        n++;

        long loop_numerator = divisor_sum(n);
        long loop_denominator = n;

        //reduce loop values
        for (int i = loop_denominator * numerator; i > 1; i--) {
            if ((loop_denominator % i == 0) && (loop_numerator % i == 0)) {
                loop_denominator /= i;
                loop_numerator /= i;
            }
        }

        if(loop_numerator == numerator && loop_denominator == denominator){
            pair_value = n;
        }
    }

    //check if pair was found or not then print if so
    if(pair_value == 0){
        return abIndex_friend(numerator, denominator, -1);
    }
    else{
        return abIndex_friend(numerator, denominator, pair_value);
    }
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
