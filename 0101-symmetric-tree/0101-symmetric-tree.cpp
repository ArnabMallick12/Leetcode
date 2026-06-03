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
    bool fn(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr || root2==nullptr){
            return root1==root2;
        }
        return (root1->val==root2->val) && fn(root1->left,root2->right)&& fn(root2->left,root1->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return fn(root->left,root->right);
    }
};