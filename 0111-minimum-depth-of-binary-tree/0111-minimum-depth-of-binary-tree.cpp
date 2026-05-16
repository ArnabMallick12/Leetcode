class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }

        // if left subtree is missing
        if(root->left == nullptr){
            return minDepth(root->right) + 1;
        }

        // if right subtree is missing
        if(root->right == nullptr){
            return minDepth(root->left) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};