/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or 
-1 if needle is not part of haystack*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(string &s,string &t){
    int i=0,j=t.size()-1;
    while(j<s.size()){
        if(s.substr(i,j-i+1)==t)return true;
        j++;
        i++;
    }
    return false;
}

int main(){
   string haystack = "leetcode", needle = "leeto";
   cout<<solve(haystack,needle);
    return 0;
}