// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int main() {
    int x;
    int first,second;
    queue<Node*>q;
    cout<<"Enter the value of root ";
    cin>>x;
    Node* root = new Node(x);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->data;
        cin>>first;
        if(first !=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        
          cout<<"Enter the right child of "<<temp->data;
        cin>>second;
        if(second !=-1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    return 0;
}

//another method
// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
Node* BinaryTree(){
    int x;
    cout<<"Enter the value";
    cin>>x;
    if(x== -1){
        return NULL;
    }
    Node* root = new Node(x);
    root->left = BinaryTree();
    root->right = BinaryTree();
    return root;
}
int main() {
Node* root = BinaryTree();
    return 0;
} 