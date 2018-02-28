#include<string>
using std::string;
#include<vector>
using std::vector;
#include <iomanip>
using std::setw;
#include <iostream>
using std::cout; using std::to_string; using std::endl;
#include "lab07_functions.h"

/*
very convenient. If you want to change the type
stored in the matrix, you only have to change the
single template type in matrix_row
*/


/*
nicely print a matrix. Should have row/column alignment
converts it to a string (doesn't print to cout!!!)
uses width to space elements (setw). Default is 3
*/
string matrix_to_str(const matrix &m1, size_t width){

    string s;

    for(auto row: m1){
        for(auto element: row){
            for(int i = 0; i < width; i++){
                s+= " ";
            }
            s+= to_string(element);
        }
        s+="\n";
    }
    return s;
}

/*
true if the two matrices have the same shape
false otherwise
*/
bool same_size(matrix &m1, matrix &m2){

    int count1 = 0;
    int count2 = 0;

    for(auto row: m1){
        for(auto element: row){
            count1++;
        }
    }

    for(auto row: m2){
        for(auto element: row){
            count2++;
        }
    }

    return count1==count2;
}

/*
matrices must not be empty and must be the same shape:
- if true, return a new matrix that adds m1+m2
- if false, return an empty matrix (no elements)
*/
matrix add(matrix &m1, matrix &m2){

    return m1;

}

/*
matrix must not be empty:
- if true, multiply T scalar value by m
- if false, return empty matrix (no elements)
*/
matrix scalar_multiply(matrix &m, long val){
    for(auto row: m){
        for(auto element: row){
            cout << element << endl;
            element*=val;
            cout << element << endl;
        }
    }
}
