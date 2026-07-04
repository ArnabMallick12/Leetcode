class Solution {
public:
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    map<int,int>& inMap) {

        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        root->left = build(postorder, postStart, postStart + numLeft - 1,
                           inorder, inStart, inRoot - 1, inMap);

        root->right = build(postorder, postStart + numLeft, postEnd - 1,
                            inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(postorder, 0, postorder.size() - 1,
                     inorder, 0, inorder.size() - 1, inMap);
    }
};
