 int height(Node* root) {
     if(root == NULL) return 0;
     int LH = height(root->left);
     int RH = height(root->right);
     return max(RH,LH)+1;
 }