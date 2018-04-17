#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<random>
using std::mt19937_64; using std::uniform_int_distribution;
#include<chrono>
#include<algorithm>
using std::generate; using std::min_element; using std::sort;
using std::upper_bound; using std::rotate; using std::copy;
#include<iterator>
using std::ostream_iterator; using std::distance;
#include<utility>
using std::swap;


void stl_selection(long ary[], size_t sz){
    long *element;
    size_t indx;
    for(size_t i=0; i<sz; i++){
	element = min_element( (ary+i), (ary+sz) );
	indx = distance(ary,element);
	swap(ary[indx], ary[i]);
    }
}

void loop_selection(long ary[], size_t sz){
    size_t min_index;
    long temp;
    for(size_t i=0;i<sz;i++){
	min_index=i;
	for(size_t j=i+1;j<sz;j++)
	    if (ary[j] < ary[min_index])
		min_index=j;
	// swap(ary[i], ary[min_index]);
	temp = ary[i];
	ary[i] = ary[min_index];
	ary[min_index] = temp;
    }
}

void stl_insert_sort(long ary[], size_t sz){
  long* upr;
  for(size_t i=0; i<sz; i++){
    upr = upper_bound(ary, ary+i, ary[i]);
    rotate(upr, ary+i, ary+(i+1));
  }
}

void insertion_sort(long ary[], size_t sz){
  int i, j;
  long to_place;
    for(j = 1; j < sz; j++){
	to_place = ary[j];
	for(i = j - 1; (i >= 0) && (ary[i] > to_place); i--) 
	    ary[i+1] = ary[i];
	ary[i+1] = to_place; 
    }
}


void fill_random(long ary[], size_t sz,
		 mt19937_64& reng, uniform_int_distribution<long>& dist){
  generate(ary, ary+sz,
	   [&](){
	     return dist(reng);
	   }
	   );
}
   
int main (){
    mt19937_64 reng;
    size_t sz;
    cin >> sz;
    uniform_int_distribution<long> dist(1,sz);
    long* ary = new long[sz];
    using time_unit = std::chrono::microseconds;

    // C++ sort
    fill_random(ary, sz, reng, dist);
    auto start = std::chrono::steady_clock::now();
    sort(ary, ary+sz);
    auto duration = std::chrono::duration_cast<time_unit>(
            std::chrono::steady_clock::now() - start);
    cout << "C++ sort:"<<duration.count() << endl;

    // selection using min_element
    fill_random(ary, sz, reng, dist);
    start = std::chrono::steady_clock::now();
    stl_selection(ary, sz);
    duration = std::chrono::duration_cast<time_unit>(
            std::chrono::steady_clock::now() - start);
    cout << "STL_selection:"<<duration.count() << endl;

    // basic selection sort
    fill_random(ary, sz, reng, dist);
    start = std::chrono::steady_clock::now();
    loop_selection(ary, sz);
    duration = std::chrono::duration_cast<time_unit>(
            std::chrono::steady_clock::now() - start);
    cout << "Loop selection:"<<duration.count() << endl;

    // stl insertion
    fill_random(ary, sz, reng, dist);
    start = std::chrono::steady_clock::now();
    stl_insert_sort(ary, sz);
    duration = std::chrono::duration_cast<time_unit>(
            std::chrono::steady_clock::now() - start);
    cout << "stl insert:"<<duration.count() << endl;
    
    // insertion sort
    fill_random(ary, sz, reng, dist);
    start = std::chrono::steady_clock::now();
    insertion_sort(ary, sz);
    duration = std::chrono::duration_cast<time_unit>(
            std::chrono::steady_clock::now() - start);
    cout << "Insertion:"<<duration.count() << endl;

    
}    

