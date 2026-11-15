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
    ListNode* reverseList(ListNode* head) {
        if(head ==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*node1=head;
        ListNode*next1=node1->next; 
        node1->next=nullptr;
        ListNode*ans=reverseList(next1);
        next1->next=node1;
        return ans;
    }
};