void printPostorder(Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
