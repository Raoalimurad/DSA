 int sumNodes(Node* root) {
     if(root == NULL) return 0;
     int leftCount = sumNodes(root->left);
     int rightCount =sumNodes(root->right);
     return (leftCount+rightCount)+root->data;
 }