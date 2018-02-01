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
int main() {
    
    long input = 0;
    long first_num = 0;
    long second_num = 0;

    //divisor sum
    cout << "input a number to get divisor sum: ";
    cin >> input;

    long sum = divisor_sum(input);

    cout << "The divisor sum is: " << sum << endl;

    //gcd
    cout << "input two numbers to find their GCD seperated by a space: ";
    cin >> first_num >> second_num;
    long greatest_divisor = gcd(first_num, second_num);
    cout << "the greatest divisor of those two is: " << greatest_divisor << endl;

    return 0;
}