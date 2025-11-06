using reverse preorder seqeunce means : right->left->root
public:
 TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        flatten(root->right);
         flatten(root->left);
         root->left = NULL;
         root->right = nextRight;
         nextRight = root;
    }
}; 