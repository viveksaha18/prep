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
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        // {node, vertical}
        queue<pair<Node*, int>> q;
        // {vertical, node->val}
        map<int, int> mpp;
        q.push({root, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int vertical = p.second;
            mpp[vertical] = node->data;
            if(node->left != nullptr) q.push({node->left, vertical-1});
            if(node->right != nullptr) q.push({node->right, vertical+1});
        }
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};