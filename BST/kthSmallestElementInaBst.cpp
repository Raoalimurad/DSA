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
 void inOrderTraversal(TreeNode*root,vector<int>&ans){
    if(!root)return;
    inOrderTraversal(root->left,ans);
    ans.push_back(root->val);
    inOrderTraversal(root->right,ans);
 }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inOrderTraversal(root,ans);
        return ans[k-1];
    }
};

////optimize approach in 0(1) space not  use of vector 

class Solution {
public:
void findSmall(TreeNode* root,int& k,int &ans){
    if(!root || k<=0) return ;
    findSmall(root->left,k,ans);
    k--;
    if(k>=0){
        ans=root->val;
    }
    findSmall(root->right,k,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        findSmall(root,k,ans);
        return ans;
    }
};