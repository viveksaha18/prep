class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // {root, {vertical, level}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        // vertical->level->{node->val}
        map<int, map<int, multiset<int>>> mpp;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            mpp[vertical][level].insert(node->val);
            if(node->left != nullptr) {
                q.push({node->left, {vertical-1, level+1}});
            }
            if(node->right != nullptr) {
                q.push({node->right, {vertical+1, level+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto it : mpp) {
            vector<int> col;
            for(auto y : it.second) {
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};