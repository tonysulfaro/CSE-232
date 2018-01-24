#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl;

//main function that juggles
int main() {

    long beginning, end, largest_number, largest_number_location, digit_count, temp_digit_count, digit_count_location;
    int print_condition;

    //get user input
    cin >> beginning;
    cin >> end;
    cin >> print_condition; //1 for valid ones and 0 for not valid ones

    //error handling
    if(beginning > end){
        cout << "Error";
    }

    //mainloop for each number in the range
    for (beginning; beginning <= end; beginning++){

        int temp = beginning;

        if(print_condition == 1){   //only print if user says to
            cout << beginning << ": ";
        }

        //find sequence for each number
        while (temp != 1){
            temp_digit_count++;
            if (temp % 2 == 0){
                temp = long(floor(pow(temp, .5)));
            }
            else{
                temp = long(floor(pow(temp, 1.5)));
            }

            //only print if user specifies
            if(print_condition == 1){
                if (temp == 1) {
                    cout << temp;
                    cout << endl;
                }
                else{
                    cout << temp << ",";
                }
            }

            //find largest number
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
