#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data) {
    val = data;
    left = right = nullptr;
    }
};
vector<int> ans;

bool path(TreeNode* root, int node) {
    if(root == nullptr) {
        return false;
    }
    
    ans.push_back(root->val);
    if(root->val == node) return true;
    if(path(root->left, node) ||path(root->right, node)) return true;
    ans.pop_back();
    return false;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    
    path(root, 8);
    for(auto it : ans) cout << it << "->";
    
    return 0;
}