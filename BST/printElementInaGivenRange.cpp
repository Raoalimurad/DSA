class Solution {
  public:
    void printBST(Node* root,int low,int high,vector<int>&ans){
        if(!root)return;
        if(root->data > low && root->data >high){
            printBST(root->left,low,high,ans);
        }else if(root->data<low && root->data <high){
            printBST(root->right,low,high,ans);
        }else{
            printBST(root->left,low,high,ans);
            ans.push_back(root->data);
            printBST(root->right,low,high,ans);
        }
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int>ans;
        printBST(root,low,high,ans);
        return ans;
    }
};