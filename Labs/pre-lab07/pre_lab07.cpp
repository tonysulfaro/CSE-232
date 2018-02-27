#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<algorithm>
using std::copy; using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
#include<string>
using std::string;

template<typename T>
void func(vector<T> &v){
     auto h=v.begin(), l=v.begin();
     T temp = *h;
     for (auto itr=v.begin(); itr!=v.end(); itr++){
       if(*itr > *h)                                        // Line 1
        h = itr;
       if (*itr < *l)
        l = itr;
     }
     temp = *h;
     *h = *l;
     *l = temp;
     cout << temp <<", "<< *h <<", "<< *l <<endl;     // Line 2
}

int main(){
     vector<long> my_v;
     for(int i=-1; i<5; ++i)
        my_v.push_back(i*2);

     copy(my_v.begin(), my_v.end(), ostream_iterator<long>(cout, ", ")); // Line 3
     cout << endl;

     func(my_v);
     copy(my_v.begin(), my_v.end(), ostream_iterator<long>(cout, ", ")); // Line 4
     cout << endl;

     ostringstream oss;
     copy (my_v.begin(), my_v.end(), ostream_iterator<long>(oss, ", ") );
     string s;
     s = oss.str();
     s = s.substr(0, s.size() - 2);
     cout << s.front() << endl;                           // Line 5
     cout << s.back() << endl;                            // Line 6
     cout << s << endl;                                   // Line 7

     transform(my_v.begin(), my_v.end(), my_v.begin(),
              [](long l){return l*l;}
              );
     cout << my_v.front() << endl;                        // Line 8
}
