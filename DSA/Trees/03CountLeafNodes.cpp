#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};
void countLeafNodes(TreeNode* root) {
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr) {
        cnt = cnt + 1;
        return;
    }
    countLeafNodes(root->left);
    countLeafNodes(root->right);
}
int main() {    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    countLeafNodes(root);
    cout << cnt;
    return 0;
}