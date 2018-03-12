#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;

using Collatz = pair<long, vector<long> >;

/*
  input is a positive (1 or greater) integer
  returns the next collatz number
  if number is 0 or less, throws range_error;
 */
long collatz_next(long n);

/*
  input is a Collatz pair (pair<long, vector<long > >)
  output is a string of the format
     number: sequence (comma separated) ending in 1
     no trailing comma
*/
string Collatz_to_string(const Collatz &p);

/*
  input is a collatz map (map<long, vector<long> >)and a long
  if the number exists as a key in the map
     returns the Collatz_to_string of that pair
  otw returns an empty string
*/
string sequence_in_map_to_string(map<long, vector<long> > &m, long number);

/*
  input is a collatz map (map<long, vector<long> >)and a long
  returns a vector<long>, the collatz sequence for that number
  Operation. As you iterate through the collatz sequence
     - uses collatz_next if the element in question is not in the map
     - if the element *is* in the map, copies the sequence from the map
       to the end of the current sequence and ends.
*/
vector<long> collatz_sequence(map<long, vector<long> > &m, long number);

/*
  input is a collatz map (map<long, vector<long> >)and a low and high long
  fills the map from low to high inclusive with each element's collatz sequence
  using the function collatz_sequence
*/
void collatz_range(map<long, vector<long> > &m, long low, long high);
