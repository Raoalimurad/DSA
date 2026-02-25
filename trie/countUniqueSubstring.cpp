// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class TrieNode{
    public:
    TrieNode* children[26];
    bool endofword;
    TrieNode(){
        for(int i = 0;i<26;i++){
            children[i] = nullptr;
        }
        endofword = false;
    }
};
TrieNode* root = new TrieNode();
void insert(string word){
    TrieNode* curr = root;
    for(char ch:word){
        int idx = ch-'a';
        if(curr->children[idx] == nullptr){
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->endofword = true;
}
int countNodes(TrieNode* root){
    if(!root) return 0;
    int count = 0;
    for(int i =0 ;i<26;i++){
        count+=countNodes(root->children[i]);
    }
  return  count+1;
}

int main() {
  string str= "ababa";
  string suffix = "";
  int n = str.length();
  for(int j =n-1;j>=0;j-- ){
      suffix = str[j]+suffix;
      insert(suffix);
  }
  int ans = countNodes(root);
  cout<<ans;
    return 0;
}