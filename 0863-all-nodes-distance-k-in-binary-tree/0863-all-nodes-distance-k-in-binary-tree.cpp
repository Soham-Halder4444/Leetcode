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
    bool parent(TreeNode* root, TreeNode* target, deque<TreeNode*>& q) {
        if (root == NULL) {
            return false;
        }

        if (root == target) {
            return true;
        }

        if (parent(root->left, target, q)) {
            q.push_back(root);
            return true;
        }

        if (parent(root->right, target, q)) {
            q.push_back(root);
            return true;
        }

        return false;
    }

    void solve(TreeNode* root, int k, vector<int>& ans) {
        if (root == NULL || k < 0) {
            return;
        }

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        solve(root->left, k - 1, ans);
        solve(root->right, k - 1, ans);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        deque<TreeNode*> q;

        parent(root, target, q);

        solve(target, k, ans);

        TreeNode* child = target;
        int dist = 1;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop_front();

            if (dist == k) {
                ans.push_back(node->val);
            }

            if (dist < k) {
                if (node->left == child) {
                    solve(node->right, k - dist - 1, ans);
                }
                else {
                    solve(node->left, k - dist - 1, ans);
                }
            }

            child = node;
            dist++;
        }

        return ans;
    }
};