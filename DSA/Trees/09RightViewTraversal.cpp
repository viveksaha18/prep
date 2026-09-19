/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        if(root == nullptr) return {};
        // {node}
        queue<Node*> q;
        vector<vector<int>> lArray;
        vector<int> ans;
        q.push({root});
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                Node* currNode = q.front();
                q.pop();
                if(currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr) {
                    q.push(currNode->right);
                }
                level.push_back(currNode->data);
            }
            lArray.push_back(level);
        }
        for(auto it : lArray) {
            if(it.size() > 1) {
                int val = it[it.size()-1];
                ans.push_back(val);
            }
            else {
                ans.push_back(it[0]);
            }
        }
        return ans;
        
    }
};