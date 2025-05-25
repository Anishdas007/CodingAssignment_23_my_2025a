// Given a string ss, return the longest palindromic substring in ss
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkPallindrome(string &s,int i,int j,vector<vector<int>>&dp){
    if(i>=j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]!=s[j]) return  dp[i][j]=0;
    return dp[i][j]=checkPallindrome(s,i+1,j-1,dp);
}

string lps(string &s){
    string ans="";
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            string ss=s.substr(i,j-i+1);
            if(checkPallindrome(ss,0,j-i,dp)){
               if(ans.size()<ss.size())ans=ss;
            }
        }
    }
    return ans;
}


int main(){
   string s="aaaaaaaaaa";
   cout<<lps(s)<<endl;
}