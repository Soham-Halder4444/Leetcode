/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertnode(Node*&head,Node*&tail,int d){
        Node* newnode=new Node(d);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node*clonehead=NULL;
        Node*clonetail=NULL;
        Node*temp=head;
        while(temp!=NULL){
            insertnode(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
        Node*originalnode=head;
        Node*clonenode=clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
            Node*front=originalnode->next;
            originalnode->next=clonenode;
            originalnode=front;
            front=clonenode->next;
            clonenode->next=originalnode;
            clonenode=front;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random?temp->random->next:temp->random;
            }
            temp=temp->next->next;
        }
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
            originalnode->next=clonenode->next;
            originalnode=originalnode->next;
            if(originalnode!=NULL){
                clonenode->next=originalnode->next;
            }
            clonenode=clonenode->next;
        }
        return clonehead;
    }
};