/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        map<int,int>m;
        q.push({root,0});
        while(!q.empty()){
            Node* curr = q.front().first;
            int distance = q.front().second;
             q.pop();
             
                 m[distance] = curr->data;
             
             if(curr->left){
                 q.push({curr->left,distance-1});
             }
             if(curr->right){
                 q.push({curr->right,distance+1});
             }
        }
        vector<int>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};












/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        map<int,int>m;
        q.push({root,0});
        while(!q.empty()){
            Node* curr = q.front().first;
            int distance = q.front().second;
             q.pop();
             
                 m[distance] = curr->data;
             
             if(curr->left){
                 q.push({curr->left,distance-1});
             }
             if(curr->right){
                 q.push({curr->right,distance+1});
             }
        }
        vector<int>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};












