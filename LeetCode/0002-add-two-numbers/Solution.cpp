/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<cmath>
class Solution {
public:
    int sum;
    int carry=0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1=l1->val;
        int val2=l2->val;
        sum=val1+val2+carry;
        carry=sum/10;
        int d=sum%10;
        ListNode*temp=new ListNode(d);
        ListNode*head=temp;
        ListNode*tail=temp;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL){
            val1=l1->val;
            val2=l2->val;
            sum=val1+val2+carry;
            carry=sum/10;
            d=sum%10;
            ListNode*temp=new ListNode(d);
            tail->next=temp;
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL){
            int val1=l1->val;
            sum=val1+carry;
            carry=sum/10;
            d=sum%10;
            ListNode*temp=new ListNode(d);
            tail->next=temp;
            tail=tail->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            int val2=l2->val;
            sum=val2+carry;
            carry=sum/10;
            d=sum%10;
            ListNode*temp=new ListNode(d);
            tail->next=temp;
            tail=tail->next;
            l2=l2->next;
        }
        while(carry!=0){
            sum=carry;
            carry=sum/10;
            int d=sum%10;
            ListNode*temp=new ListNode(d);
            tail->next=temp;
        }
        return head;

    }
};