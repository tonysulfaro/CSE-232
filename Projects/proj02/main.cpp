#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl;

//main function that juggles
int main() {

    long beginning, end, largest_number, digit_count;
    int print_condition;

    //get user input
    cin >> beginning;
    cin >> end;
    cin >> print_condition; //1 for valid ones and 0 for not valid ones

    //mainloop for each number in the range
    for (beginning; beginning <= end; beginning++){

        int temp = beginning;

        cout << beginning << ": ";

        //find sequence for each number
        while (temp != 1){
            if (temp % 2 == 0){
                temp = long(floor(pow(temp, .5)));
            }
            else{
                temp = long(floor(pow(temp, 1.5)));
            }

            //determine which is the largest number in a sequence and how many

            if (temp == 1) {
                cout << temp;
                cout << endl;
            }
            else{
                cout << temp << ",";
            }
            digit_count++;
        }
        digit_count = 0;
    }
    return 0;
}
