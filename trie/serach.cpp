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
////search in Trie
bool search(string word){
    TrieNode* curr = root;
    for(char ch:word){
        int idx = ch-'a';
        if(curr->children[idx] == nullptr){
            return false;
        }
        curr=curr->children[idx];
    }
  return  curr->endofword;
}
int main() {
 string words[5] = {"the","a","there","their","any"};
    for(int i = 0;i< 5;i++){
        insert(words[i]);
    }
 bool isPresent = search("the");
   if(isPresent){
       cout<<"yes this is present";
   }else{
       cout<<"No present";
   }
    return 0;
}