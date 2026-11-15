/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,TreeNode* p,deque<TreeNode*>&q1){
        if(root==NULL){
            return false;
        }
        if(root == p){
            q1.push_back(root);
            return true;
        }
        int left=solve(root->left,p,q1);
        if(left!=false){
            q1.push_back(root);
            return true;
        }
        int right=solve(root->right,p,q1);
        if(right!=false){
            q1.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*>q1;
        deque<TreeNode*>q2;
        bool a=solve(root,p,q1);
        bool b=solve(root,q,q2);
        TreeNode* ans;
        while(!q1.empty() && !q2.empty()){
            if(q1.back()==q2.back()){
                ans=q1.back();
                q1.pop_back();
                q2.pop_back();
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};