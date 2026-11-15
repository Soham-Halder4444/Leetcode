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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode*anshead=nullptr;
        ListNode*anstail=nullptr;
        ListNode*curr=head;
        int flag=0;
        while(curr!=nullptr){
            int val=k;
            ListNode*prev=nullptr;
            ListNode*temp=curr;
            int check=k;
            while(check && temp!=nullptr){
                temp=temp->next;
                check--;
            }
            if(check!=0){
                flag=1;
            }
            if(flag==0){
                while(val){
                    ListNode*next=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=next;
                    val--;
                }
                if(anshead==nullptr){
                    anshead=prev;
                    anstail=prev;
                    anstail=anstail->next;
                    while(anstail->next!=nullptr){
                        anstail=anstail->next;
                    }
                }
                else{
                    anstail->next=prev;
                    anstail=anstail->next;
                    while(anstail->next!=nullptr){
                        anstail=anstail->next;
                    }
                }
            }
            else{
                if(anshead==nullptr){
                    anshead=curr;
                }
                else{
                    anstail->next=curr;
                }
                break;
            }
        }
        return anshead;
    }
};