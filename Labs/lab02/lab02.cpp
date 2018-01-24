#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; using std::fixed;

int main(){

    long number_input = 0;
    long persistence = 0;
    long additive = 0;
    long sum = 0;

    cin >> number_input;
    additive = number_input;

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
        cout << persistence << "  " << additive << endl;
    }
    else{
        while(additive > 9){

            while(additive !=0){
                sum += additive % 10;
                additive /= 10;
                //cout << "Number:" << number_input << endl;


            }
            additive = sum;
            persistence++;
            sum = 0;

    }
    cout << persistence << "  " << additive << endl;
}

}
