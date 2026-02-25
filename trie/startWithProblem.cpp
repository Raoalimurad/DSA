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

bool startWith(string prefix){
    TrieNode* curr = root;
    for(char ch:prefix){
        int idx = ch-'a';
        if(curr->children[idx] == nullptr){
            return false;
        }
        curr = curr->children[idx];
    }
    return true;
}
int main() {
 string words[5] = {"apple","app","mango","samsung","man"};
    for(int i = 0;i< 5;i++){
        insert(words[i]);
    }
  bool isCheck = startWith("man");
   if(isCheck){
       cout<<"yes";
   }
    return 0;
}