class Solution {
  public:
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        while(!q.empty()) {
            auto el = q.front();
            q.pop();
            Node* newnode = el.first;
            int line = el.second;
            if(mpp.find(line) == mpp.end()) mpp[line] = newnode->data;
            if(newnode->left != nullptr) {
                q.push({newnode->left, line-1});
            }
            if(newnode->right != nullptr) {
                q.push({newnode->right, line+1});
            }
        }
        vector<int> ans;
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};