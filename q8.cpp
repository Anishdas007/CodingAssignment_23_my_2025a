//8. Group Anagrams Given an array of strings, group the anagrams together.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>solve(vector<string>&words){
    unordered_map<string,vector<string>>mp;
    for(int i=0;i<words.size();i++){
        string k=words[i];
        sort(k.begin(),k.end());
        mp[k].push_back(words[i]);
    }
    vector<vector<string>>ans;
    for(auto an:mp){
        ans.push_back(an.second);
    }
    return ans;
}


int main(){
    vector<string>words= {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>>st=solve(words);
    for(int i=0;i<st.size();i++){
        for(int j=0;j<st[i].size();j++){
            cout<<st[i][j]<<" ";
        }
        cout<<endl;
    }

}