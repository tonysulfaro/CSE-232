#ifndef MATRIX_TYPE
#define MATRIX_TYPE

#include<string>
using std::string;
#include<vector>
using std::vector;

/*
very convenient. If you want to change the type
stored in the matrix, you only have to change the
single template type in matrix_row
*/
using matrix_row = vector<long>;
using matrix = vector<matrix_row>;

/* 
nicely print a matrix. Should have row/column alignment
converts it to a string (doesn't print to cout!!!)
uses width to space elements (setw). Default is 3
*/
string matrix_to_str(const matrix &m1, size_t width=3);

/*
true if the two matrices have the same shape
false otherwise
*/
bool same_size(matrix &m1, matrix &m2);

/*
matrices must not be empty and must be the same shape:
- if true, return a new matrix that adds m1+m2
- if false, return an empty matrix (no elements)
*/
matrix add(matrix &m1, matrix &m2);

/* 
matrix must not be empty:
- if true, multiply T scalar value by m
- if false, return empty matrix (no elements)
*/
matrix scalar_multiply(matrix &m, long val);

#endif
