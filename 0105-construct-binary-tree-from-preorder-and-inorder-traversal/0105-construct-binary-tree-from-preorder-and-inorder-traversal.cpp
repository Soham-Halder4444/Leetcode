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
    int find(vector<int>&inorder,int val){
        for(int i=0;i<inorder.size();i++){
            if(val==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &in,int pres,int pree){
        if (pres > pree) {
            return NULL;
        }
        TreeNode*node=new TreeNode(preorder[in++]);
        int index=find(inorder,node->val);
        TreeNode*left=build(preorder,inorder,in,pres,index-1);
        TreeNode*right=build(preorder,inorder,in,index+1,pree);
        node->left=left;
        node->right=right;
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {   
        int in=0;
        return build(preorder,inorder,in,0,preorder.size()-1);
    }
};