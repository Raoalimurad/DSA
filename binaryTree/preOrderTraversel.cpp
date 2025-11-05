void preOrderTraversel(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrderTraversel(root->left);
    preOrderTraversel(root->right);
}
///T.C = (0n)