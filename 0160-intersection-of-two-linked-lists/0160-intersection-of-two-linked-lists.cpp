/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    #include<map>;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *,bool>m;
        while(headA!=NULL){
            m[headA]=true;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(m[headB]!=true){
                headB=headB->next;
            }
            else{
                return headB;
            }
        }
        return NULL;
    }
};