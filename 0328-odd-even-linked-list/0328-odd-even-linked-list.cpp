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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr){
            return head;
        }
        ListNode*oddhead=head;
        ListNode*oddtail=head;
        ListNode*evenhead=head->next;
        ListNode*eventail=head->next;
        oddhead->next=nullptr;
        ListNode*start=evenhead->next;
        evenhead->next=nullptr;
        int cnt=-1;
        while(start!=NULL){
            if(cnt==-1){
                oddtail->next=start;
                oddtail=oddtail->next;
                start=start->next;
            }
            else{
                eventail->next=start;
                eventail=eventail->next;
                start=start->next;
            }
            cnt*=-1;
        }
        oddtail->next=evenhead;
        eventail->next=nullptr;
        return oddhead;
    }
};