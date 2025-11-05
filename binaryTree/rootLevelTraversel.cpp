void RootLevelTraversel(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

///line wise traversel show 
//   
void RootLevelTraversel(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<curr->data<<" ";
        
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}