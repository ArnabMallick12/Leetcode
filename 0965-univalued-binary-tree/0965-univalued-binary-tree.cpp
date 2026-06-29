class Solution {
public:
    bool dfs(TreeNode* node) {
        if (node == nullptr)
            return true;

        if (node->left) {
            if (node->left->val != node->val)
                return false;
        }

        if (node->right) {
            if (node->right->val != node->val)
                return false;
        }

        return dfs(node->left) && dfs(node->right);
    }

    bool isUnivalTree(TreeNode* root) {
        return dfs(root);
    }
};