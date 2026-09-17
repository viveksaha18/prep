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
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                TreeNode* newNode = q.front();
                q.pop();
                if(newNode->left != nullptr) {
                    q.push(newNode->left);
                } 
                if(newNode->right != nullptr) {
                    q.push(newNode->right);
                }
                level.push_back(newNode->val);
            }
            if(flag == false) {
                reverse(level.begin(), level.end());
                ans.push_back(level);
                flag=true;
            }
            else {
                flag = false;
                ans.push_back(level);
            }
        }
        return ans;
    }
};