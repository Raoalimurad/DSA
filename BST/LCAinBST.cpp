/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* findLCA(TreeNode* root,int n,int m){
     if(!root) return NULL;
     if(root->val>n && root->val >m){
        return findLCA(root->left,n,m);
     }else if(root->val < n && root->val <m){
        return findLCA(root->right,n,m);
     }else{
        return root;
     }
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p->val,q->val);
    }
};