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
    void solve(TreeNode* root,int row,map<int,vector<int>>&m){
        if(root==NULL){
            return;
        }
        m[row].push_back(root->val);
        solve(root->left,row+1,m);
        solve(root->right,row+1,m);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,vector<int>>m;
        solve(root,0,m);
        vector<int>ans;
        for(auto i:m){
            ans.push_back(i.second.back());
        }
        return ans;
    }
};