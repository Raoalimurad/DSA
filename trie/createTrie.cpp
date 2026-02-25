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
void print(TrieNode* root,string& temp){
     if(root->endofword == true){
         cout<<temp<<" ";
     }
    for(int i =0; i<26;i++){
        if(root->children[i]){
            temp.push_back('a'+i);
            print(root->children[i],temp);
            temp.pop_back();
        }
    }
}
int main() {
 string words[5] = {"the","a","there","their","any"};
    for(int i = 0;i< 5;i++){
        insert(words[i]);
    }
    string temp = "";
    print(root,temp);
    return 0;
}