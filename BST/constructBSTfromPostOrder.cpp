/*struct Node
{
    int data;
    Node *left, *right;
};*/
Node* BST(int arr[],int &size,int L,int R){
    if(size < 0 || arr[size]<L || arr[size] > R){
        return NULL;
    }
    Node* root = new Node(arr[size--]);
    root->right =  BST(arr,size,root->data,R);
     root->left =  BST(arr,size,L,root->data);
      return root;  
    
}
Node *constructTree(int post[], int size) {
    // code here
    int index = size-1;
    return BST(post,index,INT_MIN,INT_MAX);
}