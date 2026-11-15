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
    ListNode*left2;
    ListNode* reverseList(ListNode*node,int cnt,int right) {
        ListNode*next=node->next;
        ListNode*curr=node;
        while(cnt!=right){
            ListNode*nextnext=next->next;
            next->next=curr;
            curr=next;
            next=nextnext;
            cnt++;
        }
        left2->next=next;
        return curr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt=left;
        ListNode*left1=NULL;
        left2=head;
        while(cnt>1){
            left1=left2;
            left2=left2->next;
            cnt--;
        }
        ListNode*head1=reverseList(left2,left,right);
        if(left1==NULL){
            return head1;
        }
        else{
            left1->next=head1;
            return head;
        }
    }
};