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
    void solve(TreeNode* root,int &maxlen,int len){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            maxlen=max(maxlen,len);
            return;
        }
        solve(root->left,maxlen,len+1);
        solve(root->right,maxlen,len+1);
    }
    int maxDepth(TreeNode* root) {
        int maxlen=0;
        solve(root,maxlen,1);
        return maxlen;
    }
};