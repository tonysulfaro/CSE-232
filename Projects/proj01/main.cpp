#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; //not really sure if this is bad practice or not

//main method
int main(){

    //initialize variables
    double car_price;
    double sales_tax_rate;
    double down_payment;
    double title_and_fees;
    double yearly_interest;
    double month_duration;
    double monthly_rate;

    //get user input
    cin >> car_price;
    cin >> sales_tax_rate;
    cin >> down_payment;
    cin >> title_and_fees;
    cin >> yearly_interest;
    cin >> month_duration;

    //calculate monthly payment
    double monthly_payment_minus_fees = car_price - down_payment * ((monthly_rate * pow((1 + monthly_rate), month_duration)/ pow((1+ monthly_rate),month_duration-1)));
    cout << fixed << setprecision(2) << monthly_payment_minus_fees;
    return 0;
}