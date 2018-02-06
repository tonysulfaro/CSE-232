#include<iostream>
 using std::cout; using std::endl;
 #include<string>
 using std::string;

 string fn1(string s1, char c){
   string result ="";
   for (auto var1 : s1){              // Line 1
     if (var1 > c)
       result += var1;
     else
       result += c;
   }
   return result;
 }

 long fn2(string& s1, char c){
   long cnt=0;
   for(auto i = 0; i<s1.size(); i++){  // Line 2
     if (s1[i] == c)
       s1[i] = 'a';
       cnt++;

   }
   return cnt;
 }


 int main (){
   string s = "mother";
   char c = 'h';
   cout << fn1 (s,c) << endl;        // Line 3
   cout << s << endl;                // Line 4
   cout << fn2 (s,c) << endl;        // Line 5
   cout << s << endl;                // Line 6

 }
