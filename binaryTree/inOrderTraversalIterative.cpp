/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }

        stack<TreeNode*>s;
        s.push(root);
        TreeNode* curr = root;
        while(curr->left){
            s.push(curr->left);
            curr = curr->left;
        }
        while(!s.empty()){
           TreeNode* temp = s.top();
            s.pop();
            if(temp->right){
                TreeNode* right = temp->right;
                s.push(right);
                while(right->left){
                    s.push(right->left);
                    right = right->left;
                }
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
}; 