#ifndef SPLITTER_FUNCTION
#define	SPLITTER_FUNCTIONS
#include<string>
#include<iostream>
using std::string; using std::ostream;
#include<vector>
using std::vector;


vector<long> vector_ops(const vector<long>& v1, const vector<long>& v2, char op);
void print_vector (ostream &out, const vector<long> &v);
