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
class Solution {
public:
    ListNode* merge(ListNode*left,ListNode*right){
        ListNode*ans;
        if(left->val<=right->val){
            ans=left;
            left=left->next;
        }
        else{
            ans=right;
            right=right->next;
        }
        ListNode* anshead=ans;
        while(left!=nullptr && right!=nullptr){
            if(left->val<=right->val){
                ans->next=left;
                ans=ans->next;
                left=left->next;
            }
            else{
                ans->next=right;
                ans=ans->next;
                right=right->next;
            }
        }
        while(left!=nullptr){
            ans->next=left;
            ans=ans->next;
            left=left->next;
        }
        while(right!=nullptr){
            ans->next=right;
            ans=ans->next;
            right=right->next;
        }
        return anshead;
    }
    ListNode* sortList(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*right=slow->next;
        slow->next=nullptr;
        ListNode*left=head;
        ListNode*sortedleft=sortList(left);
        ListNode*sortedright=sortList(right);
        return merge(sortedleft,sortedright);
    }
};