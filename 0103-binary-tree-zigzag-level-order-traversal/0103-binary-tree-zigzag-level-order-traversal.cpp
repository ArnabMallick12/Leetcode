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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool direction =false;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s);
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                int indx;
                if(direction) indx = s - i -1;
                else indx = i;
                temp[indx] = node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            ans.push_back(temp);
            direction = !direction;
        }
        return ans;   
    }
};