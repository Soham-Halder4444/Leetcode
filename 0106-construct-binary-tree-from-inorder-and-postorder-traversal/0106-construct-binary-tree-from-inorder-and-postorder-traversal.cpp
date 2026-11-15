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
        TreeNode*node=new TreeNode(preorder[in--]);
        int index=find(inorder,node->val);
        TreeNode*right=build(preorder,inorder,in,index+1,pree);
        TreeNode*left=build(preorder,inorder,in,pres,index-1);
        node->left=left;
        node->right=right;
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in=postorder.size()-1;
        return build(postorder,inorder,in,0,postorder.size()-1);
    }
};