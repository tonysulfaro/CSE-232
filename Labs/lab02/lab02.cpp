#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; using std::fixed;

int main(){

    long number_input = 0;
    long persistence = 0;
    long additive = 0;
    long sum = 0;

    cin >> number_input;

    //break if its less than 0
    if(number_input <= 0){
        //cout << "FIRST";
        cout << "Error";
        return 0;
    }
    else if(number_input <= 9){
        //cout << "SECOND";
        persistence = 0;
        additive = number_input;
        cout << persistence << "  " << additive;
    }
    else{
        while(additive == 0){
            additive = sum;
                //cout << "THIRD";
            while(number_input !=0){
                sum = sum + number_input % 10;
                number_input = number_input / 10;
                //cout << "Number:" << number_input << endl;
                cout << "SUM:" << sum << endl;

                additive = sum;
            }
            persistence++;

        }
    cout << persistence << "  " << additive;
    }
}
