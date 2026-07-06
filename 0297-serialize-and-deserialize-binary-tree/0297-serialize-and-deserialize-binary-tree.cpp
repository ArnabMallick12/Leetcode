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
        if(!root) return "#,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    TreeNode* build(string &data, int &i) {
        // Null node
        if (data[i] == '#') {
            i += 2;          // Skip "#,"
            return nullptr;
        }

        // Read the integer
        int sign = 1;
        if (data[i] == '-') {
            sign = -1;
            i++;
        }

        int num = 0;
        while (data[i] != ',') {
            num = num * 10 + (data[i] - '0');
            i++;
        }
        i++;                 // Skip ','

        TreeNode* root = new TreeNode(sign * num);
        root->left = build(data, i);
        root->right = build(data, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));