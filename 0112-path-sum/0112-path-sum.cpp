class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }

        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            return targetSum == root->val;
        }

        int rem = targetSum - root->val;

        return hasPathSum(root->left, rem) || 
               hasPathSum(root->right, rem);
    }
};