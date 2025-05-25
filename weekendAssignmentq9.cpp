/*Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal 
substring
consisting of non-space characters only.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(string &s){
    int i=s.size()-1;
    int ans=0;
    while(s[i]==' ' && i>=0){
        i--;
    }
    while((s[i]>='a'&& s[i]<='z')||(s[i]>='A' && s[i]<='Z') && i>=0){
            ans++;
        i--;
    }
    return ans;
}


int main(){
   string s = " fly me to the moon ";
   cout<<solve(s);
   return 0;
}