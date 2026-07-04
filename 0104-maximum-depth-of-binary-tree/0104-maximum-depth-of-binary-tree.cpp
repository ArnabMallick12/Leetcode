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
    int fn(TreeNode* node){
        if(node == nullptr) return 0;
        int left = 0;
        if(node->left) left  =  fn(node->left);
        int right=0;
        if(node->right) right = fn(node->right);
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
        return fn(root);
    }
};