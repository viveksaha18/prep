/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  bool isLeaf(Node* root) {
      if(root->left == nullptr && root->right == nullptr) return true;
      return false;
  }
  void f(Node* root, vector<int> temp, vector<vector<int>>& ans) {
        if(root == nullptr) return ;
        
        temp.push_back(root->data);
        
        if(isLeaf(root)) {
          ans.push_back(temp);
          temp.pop_back();
          return;
        }
        f(root->left, temp, ans);
        f(root->right, temp, ans);
        temp.pop_back();
        
     
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<int> temp;
        vector<vector<int>> ans;
        f(root, temp, ans);
        return ans;
    }
};