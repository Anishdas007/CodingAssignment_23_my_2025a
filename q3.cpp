//3. Next Greater Element Given a circular array, find the next greater number for every element.
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

int solve(vector<int> nums)
{
    int ind = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind != -1)
    {
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }

    int ans = makeNumber(nums);
    return ans;
}

int main()
{
    int num = 50221;
    vector<int> n = getArray(num);
    int ans = solve(n);
    cout << ans << endl;
    return 0;
}
