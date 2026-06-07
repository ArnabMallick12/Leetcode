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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        int childsum=0;
        for(auto v: descriptions){
            childsum+=v[1];
            if(mp.find(v[0]) == mp.end()){
                TreeNode* node = new TreeNode(v[0]);
                mp[v[0]] = node;
            }
            if(mp.find(v[1])==mp.end()){
                TreeNode* node = new TreeNode(v[1]);
                mp[v[1]] = node;
            }
            if(v[2]){
                mp[v[0]]->left = mp[v[1]];
            }
            else{
                mp[v[0]]->right = mp[v[1]];
            }
        }
        int nodesum=0;
        for(auto it:mp){
            nodesum+=it.first;
        }
        int root = nodesum-childsum;
        return mp[root];

    }
};