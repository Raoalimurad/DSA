int sumNodes(Node* root){
    if(root == NULL){
        return 0 ;
    }
    int Lsum= sumNodes(root->left);
     int Rsum   = sumNodes(root->right);
      root->data += (Lsum+Rsum);    //// ya sub tree sum tree hy qk isme root itself bi include agar isy only sum tree bananahy to root ko hatana ho ga yani root ka sum nahi hcyaee
      return root->data;
}

✅ Summary Table:
Feature	Subtree Sum Tree ✅	Sum Tree ✅
Includes root value	✅ Yes	❌ No
Leaf becomes 0	❌ No	✅ Yes
Use-case	Cumulative values	Pure tree transform
Common source	LeetCode style	GFG “Sum Tree”