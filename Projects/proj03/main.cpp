#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;

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
int main() {

    cout << "Main";
    long sum = divisor_sum(100);
    cout << sum;

    return 0;
}