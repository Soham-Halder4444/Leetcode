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
    void solve(TreeNode* root,int col,int row,map<int,map<int,vector<int>>>&m){
        if(root==NULL){
            return;
        }
        m[col][row].push_back(root->val);
        solve(root->left,col-1,row+1,m);
        solve(root->right,col+1,row+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,vector<int>>>m;
        solve(root,0,0,m);
        for(auto i : m) {
            vector<int> v;

            for(auto j : i.second) {
                vector<int> r = j.second;

                sort(r.begin(), r.end());

                for(auto x : r) {
                    v.push_back(x);
                }
            }

            ans.push_back(v);
        }
        return ans;
    }
};