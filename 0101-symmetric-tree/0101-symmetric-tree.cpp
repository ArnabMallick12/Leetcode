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
    bool fn(TreeNode* r1,TreeNode* r2){
        if(r1==nullptr || r2 == nullptr){
            return r1==r2;
        }
        return (r1->val==r2->val) && fn(r1->left,r2->right) && fn(r2->left,r1->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return fn(root->left,root->right);
    }
};