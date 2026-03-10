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
   TreeNode* BST(vector<int>& preorder,int L,int R,int &index){
        if(index == preorder.size() ||preorder[index]<L|| preorder[index]>R){
            return nullptr;
        }
        TreeNode* root =  new TreeNode(preorder[index++]);
         root->left = BST(preorder,L,root->val,index);
         root->right = BST(preorder,root->val,R,index);
         return root;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         int index = 0;
        return BST(preorder,INT_MIN,INT_MAX,index);
    }
};