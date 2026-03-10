// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1

void kSum(Node* root,int& k,int &sum){
    if(!root || k<=0) return ;
    kSum(root->left,k,sum);
    k--;
    if(k>=0){
        sum +=root->data;
    }
    
    kSum(root->right,k,sum);
    
    
    
    

}
int sum(Node* root, int k) {
    int sum1 = 0;
    kSum(root,k,sum1);
    
    return sum1;
    

    // Your code here
    
}