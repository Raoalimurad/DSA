/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//hume map ki need q hy deko agar ak clone node bana howa hy or again wo appear or ya ajata hy to hum again clone node na banee balka jo clone node phely se exist karta hy usy hi use karle that's why we use map

class Solution {
public:
        unordered_map<Node*,Node*>mp;
        void DFS(Node* node,Node* clone_Node){
            for(Node* n:node->neighbors ){
            ////clone nahi banaya abhii tak neighbour ka
                if(mp.find(n) == mp.end()){
                    Node* clone = new Node(n->val);
                    mp[n] =  clone;
                    clone_Node->neighbors.push_back(clone);
                   DFS(n,clone);
                }else{
                    ///agar clone banaya howa hy to
                    clone_Node->neighbors.push_back(mp[n]);


                }
            }
        }
    Node* cloneGraph(Node* node) {
        ///check node is null 
        if(!node){
            return NULL;
        }
        ////clone the given Node
        Node* clone_Node = new Node(node->val);
        mp[node] = clone_Node;
        ///now clone its neigbhours
        DFS(node,clone_Node);

        return clone_Node;

    }
};