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
    void inorder(vector<int> &v,TreeNode* node){
        if(node==nullptr) return;
        inorder(v,node->left);
        v.push_back(node->val);
        inorder(v,node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(in,root);
        int l=0,h = in.size()-1;
        while(l<h){
            int sum = in[l] + in[h];
            if(sum == k) return true;
            else if(sum<k) l++;
            else h--;
        }
        return false;
    }
};