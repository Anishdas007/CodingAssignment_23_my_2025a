//7. Strings Longest Substring Without Repeating Characters Given a string, find the length of the longest substring without repeating characters.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string longestString(string s){
    string ans="";
    int i=0;
    int j=0;
    unordered_map<char,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        while(mp[s[j]]>1){
            mp[s[i]]--;
            i++;
        }
        string str=s.substr(i,j-i+1);
        if(str.size()>ans.size()){
            ans=str;
        }
        j++;
    }
  
    return ans;
}



int main(){
  string s="abaabnabanb";
  cout<<longestString(s)<<endl;
}