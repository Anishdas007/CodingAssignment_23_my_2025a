/*Given two strings ss and tt, determine if tt is an anagram of a substring of ss. In other 
words, check if there exists a substring in ss that is an anagram of tt.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(string &s,string &t){
    sort(t.begin(),t.end());
    int i=0,j=t.size()-1;
    while(j<s.size()){
        string ss=s.substr(i,j-i+1);
        sort(ss.begin(),ss.end());
        if(ss==t)return true;
        i++;
        j++;
    }
    return false;
}


int main(){
   string s = "cbaebabacd", t = "abc";
   cout<<check(s,t)<<endl;
}