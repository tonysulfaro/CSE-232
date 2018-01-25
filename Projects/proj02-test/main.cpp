#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl;

//main function that juggles
int main() {

    long beginning, end, largest_number = 0, largest_number_location = 0, digit_count = 0, digit_count_location = 0;
    long print_condition, temp_digit_count = 0;

    //get user input
    cin >> beginning;
    cin >> end;
    cin >> print_condition; //1 for valid ones and 0 for not valid ones

    //error handling
    if(beginning > end){
        cout << "Error" << endl;
        return 0;
    }

    //mainloop for each number in the range
    for (beginning; beginning <= end; beginning++){

        long temp = beginning;

        if(print_condition == 1){   //only print if user says to
            cout << beginning << ": ";
        }

        //find sequence for each number
        while (temp != 1){

            if (temp % 2 == 0){
                temp = long(floor(pow(temp, .5)));
            }
            else{
                temp = long(floor(pow(temp, 1.5)));
            }
            //cout << "DIGIT COUNT " << temp_digit_count << endl;

            //only print if user specifies
            if(print_condition == 1){
                if (temp == 1) {
                    cout << temp << endl;
                }
                else{
                    cout << temp << ",";
                }
            }

            temp_digit_count++;

            //highest number
            if(temp > largest_number){
                largest_number = temp;
                largest_number_location = beginning;
            }
        }
        //find longest sequence
        if(temp_digit_count > digit_count){
            digit_count = temp_digit_count;
            digit_count_location = beginning;
        }
        temp_digit_count = 0;
    }
    cout << digit_count_location << ", " << digit_count << endl;
    cout << largest_number_location << ", " << largest_number << endl;
    return 0;
}
