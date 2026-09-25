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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            int first, last;
            int min = q.front().second;
            for(int i = 0; i < size; i++) {
                int curr = q.front().second-min;
                TreeNode* currNode = q.front().first;
                q.pop();
                if(i == 0) first = curr;
                if(i == size - 1) last = curr;
                if(currNode->left != nullptr) {
                    q.push({currNode->left, (long long)curr*2+1});
                }
                if(currNode->right != nullptr) {
                    q.push({currNode->right, (long long)curr*2+2});
                }
            }
            ans = max(ans, (last-first+1));
        }
        return ans;
    }
};