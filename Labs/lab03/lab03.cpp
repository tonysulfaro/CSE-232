#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout; using std::cin; using std::endl; using std::setprecision; using std::fixed;

//returns double of given evaluation
double fn(double x){

    //cout << "function";

    x = 6*(pow(x,2))+(5*x)+3;
    x = -x;

    return x;
}

//returns integral of a parameter
int integral(double x){

    //cout << "integral";

    x = 2*(pow(x,3))+(5*pow(x,2)/2)+(3*x);
    x = -x;

    return x;
}

//calculate area under curve fn
int trapezoid(double point_a, double point_b, long trap_count){

    //cout << "TRAPEZOID";

    double area_sum = 0;
    double range =  1;//point_b-point_a;
    double delta_x = range/trap_count;

    //add sum of sides
    for(double i = point_a; i <= point_b; i+=delta_x){

        area_sum += (delta_x)*(fn(i)+fn(i+delta_x))/2;
        cout << area_sum;
    }

    return area_sum;
}

//main method
int main(){

    //cout << "MAIN";

    int point_a = 0;
    int point_b = 1;
    float tolerance_value = 0;
    int number_guess_traps = 0;
    int number_actual_traps = number_guess_traps;
    double integral_area = 0;
    double function_area = 0;
    float actual_tolerance = abs(integral_area-function_area);

    cin >> tolerance_value;
    cin >> number_guess_traps;

    cout << fixed << setprecision(6);

    integral_area = integral(1);

    cout << integral_area;

    function_area = trapezoid(point_a, point_b, number_guess_traps);
    actual_tolerance = abs(integral_area-function_area);

    //cout << "BEFORE WHILE LOOP";

    while(actual_tolerance > tolerance_value){

        //cout << "IN WHILE LOOP";

        function_area = trapezoid(point_a, point_b, number_actual_traps);
        actual_tolerance = abs(integral_area-function_area);
        number_actual_traps++;
        cout << function_area << actual_tolerance << number_actual_traps << endl;
    }

    //cout number of traps, area values, and given tolerance

    return 0;
}
