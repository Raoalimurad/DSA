class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxWidth = 0;
       
        while(q.size() > 0){
             int currSize = q.size();
            unsigned long long startIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWidth = max(maxWidth,(int)(endIdx-startIdx+1));
            for(int i = 0; i<currSize;i++){
                auto currNode = q.front();
                q.pop();
                if(currNode.first->left != NULL){
                    q.push({currNode.first->left,currNode.second*2+1});
                }
                if(currNode.first->right != NULL){
                    q.push({currNode.first->right,currNode.second*2+2});
                }
            }
        }
        return maxWidth;
    }
};