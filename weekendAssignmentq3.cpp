/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input 
string is valid.
A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(string &s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }else if(s[i]=='}'){
            if(st.top()!='{')return false;
            else st.pop();
        }else if(s[i]==']'){
            if(st.top()!='[')return false;
            else st.pop();
        }else if(s[i]==')'){
            if(st.top()!='(')return false;
            else st.pop();
        }
    }
    if(!st.empty())return false;
    return true;
}

int main(){
    string s = "()[]{}";
    if(check(s)){
        cout<<"valid brackets"<<endl;
    }else {
        cout<<"invalid brackets"<<endl;
    }
    return 0;
}