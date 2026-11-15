/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            if(root->left==NULL){
                TreeNode*right=root->right;
                delete root;
                return right;
            }
            if(root->right==NULL){
                TreeNode*left=root->left;
                delete root;
                return left;
            }
            else{
                TreeNode*right=root->right;
                TreeNode*left=root->left;
                delete root;
                TreeNode*temp=right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                temp->left=left;
                return right;
            }
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{
            root->left=deleteNode(root->left,key);
            return root;
        }
    }
};