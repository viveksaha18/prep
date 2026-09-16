#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data1) {
        data = data1;
        left = right = nullptr;
    }
};

int findHeight(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    int lHeight = findHeight(root->left);
    int rHeight = findHeight(root->right);
    return 1 + max(lHeight, rHeight);
}
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    
    
    int height = findHeight(root);
    cout << height;
    return 0;
}