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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr|| k==0){
            return head;
        }
        ListNode*temp=head;
        int size=0;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        if(size==k){
            return head;
        }
        int cnt=1;
        ListNode*tail=head;
        int val=size-k;
        if(size<k){
            k=k%size;
            val=size-k;
        }
        while(cnt<val){
            tail=tail->next;
            cnt++;
        }
        ListNode*anshead=tail->next;
        ListNode*anstail=tail->next;
        tail->next=nullptr;
        if(anstail==nullptr){
            return head;
        }
        while(anstail->next!=nullptr){
            anstail=anstail->next;
        }
        anstail->next=head;
        return anshead;
    }
};