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
bool wordBreak(string key){
    if(key.length() == 0) return true;
    for(int i = 1;i<=key.size();i++){
        string first = key.substr(0,i);
        string second = key.substr(i);
        if(search(first)&& wordBreak(second)){
            return true;
        }
    }
    return false;
}
int main() {
 string words[5] = {"i","like","samg","samsung","mobile"};
    for(int i = 0;i< 5;i++){
        insert(words[i]);
    }
  bool isCheck = wordBreak("ilikesamg");
   if(isCheck){
       cout<<"yes";
   }
    return 0;
} 