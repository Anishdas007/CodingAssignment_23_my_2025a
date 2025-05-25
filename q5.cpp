//5. Reorder List Reorder a linked list from L0 → L1 → … → Ln-1 → Ln to L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ….

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

ll *solve(ll *head)
{
    if (!head->next || !head->next->next)
        return head;
    ll *slow = head;
    ll *fast = head;
    stack<ll *> st;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            if (fast)
            {
                slow = slow->next;
            }
        }
    }
    ll *t = slow->next;
    slow->next = NULL;
    while (t)
    {
        st.push(t);
        t = t->next;
    }
    ll *temp = head;
    ll *temp1 = temp;
    while (!st.empty())
    {
        temp1 = temp1->next;
        temp->next = st.top();
        st.pop();
        temp = temp->next;
        temp->next = temp1;
        temp = temp1;
    }
    return head;
}

int main()
{
    vector<int> nums1 = {9, 7, 8};
    ll *nums = cll(nums1);
    print(nums);
    ll *ans = solve(nums);
    print(ans);
    return 0;
}
