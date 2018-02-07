#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using std::sort; using std::string;
using std::cout; using std::cin; using std::endl;

string _alpha = "abcdefghijklmnopqrstuvwxyz";

long loc_to_dec(string loc){
   long vert = 0;
       for(unsigned int i = 0; i < loc.size(); i++){
           for(unsigned int c = 0; c < _alpha.size(); c++){
               if(loc[i] == _alpha[c]){
                   vert += pow(2.0, c);
               }

           }
       }
   return vert;
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

   string l = loc, oldl ="";
   string::size_type indx=1;
   while(indx < l.size()){
       sort(l.begin(), l.end());
       if(l[indx] == l[indx-1]){
           oldl = l;
           l = oldl.substr(0, indx-1);
           l.push_back(static_cast<char>(oldl[indx]+1));
           l+=oldl.substr(indx+1);
       }
       else{
           indx += 1;
       }
   }
   return l;
}

string dec_to_loc(long dec){
   string str = "";
   for(int i = 0; i < dec; i++){
       str.push_back('a');
   }
   sort(str.begin(), str.end());
   str = abbreviate(str);
   return str;
}

long add_loc(string loc1, string loc2){
   string ns = loc1 + loc2;
   sort(ns.begin(), ns.end());
   ns = abbreviate(ns);
   return loc_to_dec(ns);
}

int main(){
   string loc;
   int i;
   //cout<<"Location String: ";
   cin>>loc;
   //cout<<"Integer: ";
   cin>>i;
   //cout<<loc<<" "<<loc_to_dec(loc)<<endl;
   //cout<<loc<<" "<<abbreviate(loc)<<endl;
   //cout<<i<<" "<<dec_to_loc(i)<<endl;
   //cout<<add_loc(loc, loc)<<endl;

   cout<<loc_to_dec(loc) << " " << abbreviate(loc) << " " << dec_to_loc(i) << " "<< add_loc(loc, loc) << endl;
   return 0;
}
