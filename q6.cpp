//6. Remove Nth Node From End of List Given a linked list, remove the nth node from the end and return its head.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class ll
{
public:
    int val;
    ll *next;
    ll(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    ll(int val, ll *next)
    {
        this->val = val;
        this->next = next;
    }
};
ll *rev(ll *head)
{
    if (!head->next)
        return head;
    ll *curr = head;
    ll *temp = head->next;
    ll *prev = NULL;
    while (temp)
    {
        curr->next = prev;
        prev = curr;
        curr = temp;
        temp = temp->next;
    }
    curr->next = prev;
    prev = curr;
    return prev;
}

void print(ll *head)
{
    ll *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ll *cll(vector<int> &nums)
{
    ll *head = NULL;
    ll *tail = NULL;
    for (int i = 0; i < nums.size(); i++)
    {
        ll *newnode = new ll(nums[i]);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}

ll *solve(ll *head, int t)
{
    int cnt = 0;
    ll *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt < t)
        return head;
    temp = head;
    int dif = t - cnt;
    if (dif == 0)
    {
        head = head->next;
        delete (temp);
    }
    cnt = 1;
    while (cnt < dif)
    {
        temp = temp->next;
        cnt++;
    }
    ll *temp1 = temp->next;
    temp->next = temp->next->next;
    delete (temp1);
    return head;
}

int main()
{
    vector<int> nums1 = {9, 7, 8, 9, 10, 11};
    ll *nums = cll(nums1);
    print(nums);
    ll *ans = solve(nums, 5);
    print(ans);
    return 0;
}
