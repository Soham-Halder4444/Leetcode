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
    pair<int,int> solve(TreeNode* root,int &cnt){
        if(root==NULL){
            return make_pair(0,0);
        }
        if(root->left==NULL && root->right==NULL){
            cnt++;
            return make_pair(root->val,1);
        }
        pair<int,int> left=solve(root->left,cnt);
        pair<int,int> right=solve(root->right,cnt);
        int sum=left.first+right.first+root->val;
        int d=left.second+right.second+1;
        if(sum/d==root->val){
            cnt++;
        }
        pair<int,int>node=make_pair(sum,d);
        return node;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};