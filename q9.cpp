//9. Rearrange a no to find min possible no in o(n) and constant space.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> getArray(int n)
{
    vector<int> ans;
    while (n)
    {
        ans.push_back(n % 10);
        n = n / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int makeNumber(vector<int> nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans * 10 + nums[i];
    }
    return ans;
}

int solve(int num)
{
    vector<int> nums = getArray(num);
    vector<int> count(10, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }
    int j = 0;
    for (int i = 0; i < count.size(); i++)
    {
        while (count[i] != 0)
        {
            nums[j] = i;
            j++;
            count[i]--;
        }
    }
    int ans = makeNumber(nums);
    return ans;
}

int main()
{
    int num = 324;
    cout << solve(num) << endl;
    return 0;
}