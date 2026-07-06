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
class NodeVal{
    public:
    int minNode , maxNode , sum;
    NodeVal(int minNode ,int  maxNode ,int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};
class Solution {
public:
     int ans = 0;
    NodeVal  maxSumBSTHelper(TreeNode* root){
        if(!root) return NodeVal(INT_MAX,INT_MIN,0);
        NodeVal  left = maxSumBSTHelper(root->left);
        NodeVal  right = maxSumBSTHelper(root->right);

        if(root->val > left.maxNode && root->val < right.minNode){
            ans = max(ans,left.sum + right.sum + root->val);
            return NodeVal(min(root->val,left.minNode),max(root->val,right.maxNode), left.sum + right.sum + root->val);
        }
        return NodeVal(INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return ans;
    }
};