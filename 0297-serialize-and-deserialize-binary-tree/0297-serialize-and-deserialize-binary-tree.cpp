/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#,";
        }

        return to_string(root->val) + "," +
            serialize(root->left) +
            serialize(root->right);
    }
    TreeNode* solve(string data, int &idx) {

        if(data[idx] == '#') {
            idx += 2;
            return NULL;
        }

        int sign = 1;

        if(data[idx] == '-') {
            sign = -1;
            idx++;
        }

        int num = 0;

        while(data[idx] != ',') {
            num = num * 10 + (data[idx] - '0');
            idx++;
        }

        idx++; // skip ','

        num = num * sign;

        TreeNode* root = new TreeNode(num);

        root->left = solve(data, idx);
        root->right = solve(data, idx);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return solve(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));