#ifndef NSTEP_CODING
#define NSTEP_CODING

#include<string>
using std::string;
#include<vector>
using std::vector;


string vec_2_str(const vector<long>& v);

vector<long> gen_nstep_vector (long limit, long nstep);

string num_to_nstep_coding(long num, long nstep);

long nstep_coding_to_num(const string& coding, const vector<long>& nstep_sequence);

#endif
