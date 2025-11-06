void topView(Node* root) {
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if (m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }
        if (curr->left != NULL) {
            q.push({curr->left, currHD - 1});
        }
        if (curr->right != NULL) {
            q.push({curr->right, currHD + 1});
        }
    }
    for (auto it : m) {
        cout << it.second << " ";
    }
}