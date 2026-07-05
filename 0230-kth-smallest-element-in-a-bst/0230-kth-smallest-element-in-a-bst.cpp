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
    int ans ;
    void fn(TreeNode* root, int &k){
        if(root == nullptr || k<=0) return;
        fn(root->left,k);
        if(--k == 0){
            ans = root->val;
            return;
        }
        fn(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fn(root,k);
        return ans;
    }
};