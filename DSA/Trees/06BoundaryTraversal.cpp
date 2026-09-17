#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val1) {
        val = val1;
        left = right = nullptr;
    }
};
// Boolean function for check the node is leaf node or not a leaf node
bool isLeafNode(TreeNode* node) {
    if(node->left == nullptr && node->right == nullptr) return true;
    return false;
}
void leftBoundaryTraversal(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->left;
    while(curr != nullptr) {
        if(isLeafNode(curr) == false) {
            res.push_back(curr->val);
        }
        if(curr->left != nullptr) {
            curr = curr->left;
        }
        else curr = curr->right;
    }
}

void leafNodes(TreeNode* root, vector<int>& res) {
    if(root == nullptr) return;
    if(isLeafNode(root) == true) {
        res.push_back(root->val);
    }
    leafNodes(root->left, res);
    leafNodes(root->right, res);
}

void rightBoundaryTraversal(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->right;
    vector<int> rBoundary;
    while(curr != nullptr) {
        if(isLeafNode(curr) == false) {
            rBoundary.push_back(curr->val);
        }
        if(curr->right != nullptr) {
            curr = curr->right;
        }
        else curr = curr->left;
    }
    for(int i = rBoundary.size()-1; i >= 0; i--) {
        res.push_back(rBoundary[i]);
    }
}
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> res;
    res.push_back(root->val);
    leftBoundaryTraversal(root, res);
    leafNodes(root, res);
    rightBoundaryTraversal(root, res);
    return res;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    
    vector<int> ans = boundaryTraversal(root);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}