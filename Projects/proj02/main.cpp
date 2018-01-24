#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl;

//main function that juggles
int main() {

    long beginning;
    long end;
    int print_condition;

    //get user input
    cin >> beginning;
    cin >> end;
    cin >> print_condition; //1 for valid ones and 0 for not valid ones

    //mainloop
    for (beginning; beginning <= end; beginning++){

        int temp = beginning;

        cout << beginning << ": ";

        while (temp != 1){
            if (temp % 2 == 0){
                temp = long(floor(pow(temp, .5)));
            }
            else{
                temp = long(floor(pow(temp, 1.5)));
            }
            if (temp == 1) {
                cout << temp;
                cout << endl;
            }
            else{
                cout << temp << ",";
            }
        }
    }

    return 0;
}
