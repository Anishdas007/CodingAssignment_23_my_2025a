/* Subarray Sum Equals K
 Given an array of integers and a target sum k, return the total number of continuous subarrays whose sum equals to k.*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
    int solve(vector<int>&nums,int t){
        unordered_map<int,int>mp;
        mp[0]++;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-t)!=mp.end())count+=mp[(sum-t)];
             mp[sum]++;
        }
        return count;
    }
int main() {
    vector<int>nums={1,2,2,3,4,5,2,7};
    int t=7;
    cout<<solve(nums,t)<<endl;
    return 0;
}


















