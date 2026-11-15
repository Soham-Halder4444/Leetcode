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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        vector<int>a;
        if(q.front()==NULL){
            return ans;
        }
        q.push(NULL);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            a.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(q.front()==NULL){
                q.pop();
                ans.push_back(a);
                if(q.empty()){
                    return ans;
                }
                q.push(NULL);
                
                while(a.size()){
                    a.pop_back();
                }
            }
        }
        return ans;
    }
};