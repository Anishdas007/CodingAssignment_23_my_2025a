/*Linked Lists Add Two Numbers You are given two non-empty linked lists representing two non-negative integers. Add the two numbers and return the sum as a linked list.*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 class ll{
     public:
   int val;
   ll*next;
   ll(int val){
       this->val=val;
       this->next=NULL;
   }
   ll(int val,ll*next){
       this->val=val;
       this->next=next;
   }
 };
ll*rev(ll*head){
    if(!head->next)return head;
    ll*curr=head;
    ll*temp=head->next;
    ll*prev=NULL;
    while(temp){
       curr->next=prev;
       prev=curr;
       curr=temp;
       temp=temp->next;
    }
    curr->next=prev;
    prev=curr;
    return prev;
}

ll*solve(ll*ll1,ll*ll2){
    ll*t1=ll1;
    ll*t2=ll2;
    ll*ans=NULL;
    ll*tail=NULL;
    int c=0;
    while(t1 && t2){
        ll*newnode= new ll(((t1->val+t2->val+c)%10));
        c=(t1->val+t2->val)/10;
        if(ans==NULL){
            ans=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        t1=t1->next;
        t2=t2->next;
    }
    while(t1){
        ll*newnode=new ll((t1->val+c)%10);
        c=(t1->val+c)/10;
        tail->next=newnode;
        tail=tail->next;
         t1=t1->next;
      
    }
    while(t2){
         ll*newnode= new ll((t2->val+c)%10);
        c=(t2->val+c)/10;
        tail->next=newnode;
        tail=tail->next;
        t2=t2->next;
    }
  if(c!=0){
         ll*newnode=new ll(c);
        tail->next=newnode;
        tail=tail->next;
  }
  ans=rev(ans);
    return ans;
}

void print(ll*head){
    ll*temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

ll*cll(vector<int>&nums){
    ll*head=NULL;
    ll*tail=NULL;
     for(int i=0;i<nums.size();i++){
        ll*newnode=new ll(nums[i]);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    return head;
}

int main() {
    vector<int>nums1={9,9,9};
    vector<int>nums2={2};
    ll*ll1=cll(nums1);
    ll*ll2=cll(nums2);
    print(ll1);
    print(ll2);
    ll1=rev(ll1);
    ll2=rev(ll2);
    ll*ans=solve(ll1,ll2);
    print(ans);
    return 0;
}


















