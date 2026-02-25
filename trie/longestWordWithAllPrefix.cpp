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
string ans = "";
void longestWord(TrieNode* root,string& temp){
    for(int i = 0;i<26;i++){
        if(root->children[i] !=nullptr &&root->children[i]->endofword == true){
            temp.push_back('a'+i);
            if(ans.length()<temp.size()){
                ans = temp;
            }
            longestWord(root->children[i],temp);
            temp.pop_back();
        }
    }
}

int main() {
 string words[] = {"a","ap","app","appl","apply","apple","banana"};
   for(int i =0;i<7;i++){
       insert(words[i]);
   }
   string temp ="";
   cout<<ans;
   longestWord(root,temp);
   cout<<ans;
    return 0;
} 