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
    void preorder(vector<int>& v, TreeNode* node){
        if(node==nullptr){
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(node->val);
        preorder(v,node->left);
        preorder(v,node->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> preorder_p;
        vector<int> preorder_q;
        preorder(preorder_p,p);
        preorder(preorder_q,q);
        return preorder_p == preorder_q;
    }
};