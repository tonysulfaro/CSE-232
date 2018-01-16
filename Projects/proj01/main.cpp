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
    //cout << "Enter the car price.";
    cin >> car_price;

    //cout << "Enter the sales tax rate.";
    cin >> sales_tax_rate;

    //cout << "Enter the down payment.";
    cin >> down_payment;

    //cout << "Enter the title and fees.";
    cin >> title_and_fees;

    //cout << "Enter the yearly interest.";
    cin >> yearly_interest;

    //cout << "Enter the Number of months for payment.";
    cin >> month_duration;

    //calculate monthly payment
    double monthly_payment_minus_fees = car_price - down_payment * ((monthly_rate * pow((1 + monthly_rate), month_duration)/ pow((1+ monthly_rate),month_duration-1)));
    cout << fixed << setprecision(2) << monthly_payment_minus_fees;
    return 0;
}