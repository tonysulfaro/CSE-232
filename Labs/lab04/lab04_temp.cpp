#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using std::sort; using std::string;
using std::cout; using std::cin; using std::endl;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

long loc_to_dec(string loc){
   long counter = 0;
   for(auto chr:loc){
       for(unsigned int i = 0; i < alphabet.size(); i++){
           if(chr == alphabet[i]){
               counter += pow(2.0, i);
           }
       }
   }
   return counter;
}

bool single(string loc){
    for(unsigned int i = 0; i < loc.size(); i++){
       if(loc[i] == loc[i+1]){
           return false;
       }
    }
    return true;
}

string abbreviate(string loc){

   string loc_temp = loc;
   string oldl;

   string::size_type indx=1;
   while(indx < loc_temp.size()){
       sort(l.begin(), l.end());
       if(loc_temp[indx] == loc_temp[indx-1]){
           oldl = l;
           loc_temp = oldl.substr(0, indx-1);
           loc_temp.push_back(static_cast<char>(oldl[indx]+1));
           loc_temp+=oldl.substr(indx+1);
       }
       else{
           indx += 1;
       }
   }
   return l;
}

string dec_to_loc(long dec){
   string str;
   for(int i = 0; i < dec; i++){
       str.push_back('a');
   }
   sort(str.begin(), str.end());
   str = abbreviate(str);
   return str;
}

long add_loc(string loc1, string loc2){
   string concat = loc1 + loc2;
   //sort string
   sort(concat.begin(), concat.end());
   concat = abbreviate(concat);
   return loc_to_dec(concat);
}

int main(){
   string loc;
   int i;
   cin>>loc;
   cin>>i;

   cout<<loc_to_dec(loc) << " " << abbreviate(loc) << " " << dec_to_loc(i) << " "<< add_loc(loc, loc) << endl;
   return 0;
}
