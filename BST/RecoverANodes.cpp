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
    void recoverTree(TreeNode* root) {
        TreeNode* curr = nullptr;
        TreeNode* first =nullptr;
        TreeNode* second = nullptr;
        TreeNode* last = nullptr;
        TreeNode* present = nullptr;
         while(root){
            if(!root->left){
                last = present;
                present = root;
                if(last && last->val>present->val){
                   if(!first){
                        first = last;
                    }
                    second = present;
                }
                root = root->right;
            }else{
                curr = root->left;
                while(curr->right && curr->right != root){
                    curr= curr->right;
                }
                if(!curr->right){
                    curr->right = root;
                    root = root->left;
                }else{
                    curr->right = nullptr;
                    last = present;
                    present = root;
                    if(last && last->val>present->val){
                   if(!first){
                        first = last;
                    }
                    second = present;
                }
                root = root->right;

                }
            }
         }
         int num = first->val;
         first->val = second->val;
         second->val = num;
    }
};