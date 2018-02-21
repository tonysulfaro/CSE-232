#ifndef SPLITTER_FUNCTIONS
#define	SPLITTER_FUNCTIONS
#include<string>
#include<iostream>
using std::string; using std::ostream;
#include<vector>
using std::vector;

vector<string> split (const string &, char separator=' ');
void print_vector (ostream &, const vector<string> &);

#endif
