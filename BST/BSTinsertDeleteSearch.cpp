// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
     Node* right;
    Node(int val){
        data = val,
        left = right = NULL;
    }
};
// insert function.
Node* insert(Node* root,int val){
    if(!root){
        Node* temp = new Node(val);
        return temp;
    }
    ///left
    if(val<=root->data){
        root->left = insert(root->left,val);
    }
    ///right
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
///search
bool search(Node* root,int val){
    if(!root) return false;
    /// matach ho jae
    if(root->data == val){
        return true;
    }else if(val<root->data){
        return search(root->left,val);
    }else{
          return search(root->right,val);
    }
    
}
Node* Delete(Node* root,int target){
    if(!root) return NULL;
    ///left case
    if(root->data>target){
      root->left =   Delete(root->left,target);
      return root;
    }
    ///right case
    else if(root->data< target){
       root->right=Delete(root->right,target);
       return root;
    }
    ///match
    else{
        ///leaf node
        if(!root->right && !root->left){
            delete root;
            return NULL;
        }
        
        ///one child exist
        ///1) left exist;
         else if(!root->right){
             Node* temp = root->left;
             delete root;
             return temp;
         }
         ///2) right exist
         else if(!root->left){
             Node* temp = root->right;
             delete root;
             return temp;
         }else{
             //both child exist;
             Node* parent = root;
             Node* child = root->left;
             while(child->right){
                 parent = child;
                 child = child->right;
             }
             
             if(parent !=root){
                 parent->right = child->left;
                 child->left = root->left;
                 child->right = root->right;
                 delete root;
                 return child;
             }else{
                 child->right = root->right;
                 delete root;
                 return child;
             }
         }
         
    }
}
void inOrderTraversal(Node* root){
    if(!root) return ;
    inOrderTraversal(root->left);
    cout<<root->data;
     inOrderTraversal(root->right);
}
int main() {
    vector<int> arr = {3,7,4,1,6,8};
    int n = arr.size();
    Node* root = NULL;
     for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
     }
     inOrderTraversal(root);
    //  if(search(root,8)){
    //      cout<<"this val present in Bst";
    //  }
    cout<<root->data;
    cout<<endl;
 root = Delete(root,3);
     inOrderTraversal(root);
     cout<<root->data;
      
    
    return 0;
} 