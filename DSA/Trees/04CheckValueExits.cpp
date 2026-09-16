#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};
bool ans = false;
void searchValue(TreeNode* root, int value) {
    if(root == nullptr) return;
    if(root->data == value) {
        ans = true;
        return;
    }
    searchValue(root->left, value);
    searchValue(root->right, value);
}
int main() {    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int value = 34;
    searchValue(root, value);
    if(ans) cout << "True";
    else cout << "False";
    return 0;
}