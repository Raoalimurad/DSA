class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int>ans;
        stack<Node*>s1,s2;
        while(r1){
            s1.push(r1);
            r1 = r1->left;
        }
         while(r2){
            s2.push(r2);
            r2 = r2->left;
        }
        
        while(!s1.empty() && !s2.empty()){
            int elem1 = s1.top()->data;
            int elem2 =s2.top()->data;
            if(elem1 == elem2){
                r1 = s1.top()->right;
                r2 = s2.top()->right;
                ans.push_back(elem1);
                s1.pop();
                s2.pop();
            }
            else if(elem1>elem2){
                r2 = s2.top()->right;
                s2.pop();
            }else{
                r1 = s1.top()->right;
                s1.pop();
            }
            
            
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }
            
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
         
        }
        return ans;
    }
};


