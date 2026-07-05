class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> ans;

        q.push({root, {0, 0}}); // {node, {column, row}}

        while (!q.empty()) {
            auto node = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();

            mp[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});

            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        for (auto &c : mp) {
            vector<int> temp;
            for (auto &r : c.second) {
                temp.insert(temp.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};