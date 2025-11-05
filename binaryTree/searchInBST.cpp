int searchBST(Node* root,int key){
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        return root->data;
    }
    if(key< root->data){
        return searchBST(root->left,key);
    }else{
      return  searchBST(root->right,key); 
    }
}