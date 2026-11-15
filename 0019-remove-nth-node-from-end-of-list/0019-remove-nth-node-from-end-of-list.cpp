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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1){
            return nullptr;
        }
        int cnt=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int val=1;
        if(val>(cnt-n)){
            head=head->next;
            return head;
        }
        temp=head;
        while(val<(cnt-n)){
            temp=temp->next;
            val++;
        }
        temp->next=temp->next->next;
        return head;
    }
};