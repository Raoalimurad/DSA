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
bool checkBST(TreeNode* root,long &prev){
    if(!root) return 1;
    bool l = checkBST(root->left,prev);
     if(l == 0) return 0;
     if(root->val<=prev) return 0;
     prev = root->val;
     return checkBST(root->right,prev);
}
    bool isValidBST(TreeNode* root) {
      long prev = LONG_MIN;
       return checkBST(root,prev) ;
    }
};