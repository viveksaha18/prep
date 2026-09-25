/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */
class Solution {
  public:
    bool flag = true;
    bool isNotLeaf(Node* root) {
      if(root->left != nullptr || root->right != nullptr) return true;
      return false;
    }
    int  f(Node* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftValue = f(root->left);
        int rightValue = f(root->right);
        if(root->data != leftValue + rightValue && isNotLeaf(root)) {
            flag = false;
        }
        
        return root->data;
    }
    bool isSumProperty(Node *root) {
        // code here
        f(root);
        if(flag) return true;
        return false;
    }
};