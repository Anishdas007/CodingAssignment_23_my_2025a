/*Given a string paragraph and a string array of the banned words banned, return the most frequent word 
that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is 
unique.
The words in paragraph are case-insensitive and the answer should be returned in lowercase.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(vector<string>&words,vector<string>&banned){
    unordered_map<string,int>ban,mp;
    string ans="";
    int maxi=0;
    for(int i=0;i<banned.size();i++){
        ban[banned[i]]++;
    }
    for(int i=0;i<words.size();i++){
        if(ban.find(words[i])==ban.end()){
            mp[words[i]]++;
            if(maxi<mp[words[i]]){
                ans=words[i];
                maxi=mp[words[i]];
            }
        }
    }
    return ans;
}

vector<string>getArray(string &s){
    int i=0,j=0;
    vector<string>ans;
    while(j<s.size()){
        while(s[j]==' ' || s[j]==',' || s[j]=='.')j++;
        while(s[i]==' '|| s[i]==',' || s[i]=='.')i++;
        while(s[j]!=' ' && s[j]!=',' && s[j]!='.')j++;
        ans.push_back(s.substr(i,j-i));
        i=j;
    }
    return ans;
}


int main(){
   string paragraph = "a";
   vector<string>banned = {""};
   vector<string>words=getArray(paragraph);
   string ans=solve(words,banned);
   cout<<ans<<endl;
   return 0;
}