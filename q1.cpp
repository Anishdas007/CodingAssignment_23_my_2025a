
/*Two Sum II - Input array is sorted
Given a sorted array of integers, return the indices of the two numbers such that they add up to a specific target.*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
pair<int,int>solve(vector<int>&nums,int &t){
    int i=0;
    int j=nums.size()-1;
    while(i<j){
        if((nums[i]+nums[j])<t)i++;
        else if((nums[i]+nums[j])>t)j--;
        else return {i,j};
    }
    return {-1,-1};
}
int main() {
    vector<int>nums={1,2,2,3,4,52,78};
    int t=7;
    pair<int,int>ans;
    ans=solve(nums,t);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
