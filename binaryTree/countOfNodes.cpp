 int CountNodes(Node* root) {
     if(root == NULL) return 0;
     int leftCount = CountNodes(root->left);
     int rightCount =CountNodes(root->right);
     return (leftCount+rightCount)+1;
 }