class Solution {
public:
    void fn(int& ans, int& k, TreeNode* node) {
        if (!node || k <= 0) return;
        fn(ans, k, node->left);
        if (--k == 0) {
            ans = node->val;
            return;
        }
        fn(ans, k, node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        fn(ans, k, root);
        return ans;
    }
};