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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ins=new TreeNode(val);
        if(root==NULL){
            return ins;
        }
        TreeNode*node=root;
        while(1){
            if(node->val<val){
                if(node->right==NULL){
                    node->right=ins;
                    return root;
                }
                node=node->right;
            }
            else{
                if(node->left==NULL){
                    node->left=ins;
                    return root;
                }
                node=node->left;
            }

        }
        return root;
    }
};