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
    #include <cmath>
    int height(TreeNode* root,int cnt){
        TreeNode* node=root;
        while(node!=NULL){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    void solve(TreeNode* root,int &cnt){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            cnt++;
            return;
        }
        int lefth=height(root->left,0);
        int righth=height(root->right,0);
        if(lefth==righth){
            cnt+=int(pow(2,lefth));
            solve(root->right,cnt);
        }
        else{
            cnt+=int(pow(2,righth));
            solve(root->left,cnt);
        }
        
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};