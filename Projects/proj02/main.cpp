#include <iostream>
#include <cmath>

using namespace std;

//main function that juggles
int main() {

    long beginning;
    long end;
    int print_condition;

    //get user input
    cin >> beginning;
    cin >> end;
    cin >> print_condition;

    //mainloop
    for (beginning; beginning <= end; beginning++){

        int temp = beginning;

        while (temp != 1){
            if (temp % 2 == 0){
                temp = long(floor(pow(temp, .5)));
            }
            else{
                temp = long(floor(pow(temp, 1.5)));
            }
            cout << temp << " ";
            if (temp == 1){
                cout << endl;
            }
        }


    }

    return 0;
}