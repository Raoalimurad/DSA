/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
  bool Dead(Node* root,int L,int R){
      if(!root) return 0;
      if(!root->left && !root->right){
          if(root->data - L == 1 && R-root->data == 1)return 1;
          else{
              return 0;
          }
          
      }
      
      return Dead(root->left,L,root->data)|| Dead(root->right,root->data,R);
         
          
          
    

  }
    bool isDeadEnd(Node *root) {
        // Code here
       return  Dead(root,0,INT_MAX);
    }
};