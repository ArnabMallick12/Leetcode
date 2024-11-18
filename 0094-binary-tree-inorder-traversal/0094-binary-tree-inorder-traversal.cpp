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
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current != NULL || !stk.empty()) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            stk.push(current);
            current = current->left;
        }
        
        // Current must be NULL at this point
        current = stk.top();
        stk.pop();
        result.push_back(current->val);

        // Visit the right subtree
        current = current->right;
    }

    return result;
}
};