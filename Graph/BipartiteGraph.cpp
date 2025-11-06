////uisng bfs

class Solution {
  public:
  
      vector<vector<int>> constructGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(const auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj = constructGraph(V, edges);
        
       vector<int> color(V,-1);
       queue<int>q;
       for(int i = 0; i< color.size();i++){
           if(color[i] == -1){
               color[0] =0;
               q.push(0);
               while(!q.empty()){
                   int node = q.front();
                   q.pop();
                   for(int i = 0; i<adj[node].size();i++){
                       if(color[adj[node][i]] == -1){
                           color[adj[node][i]] = (color[node]+1)%2;
                           q.push(adj[node][i]);
                       }else{
                           if(color[node] == color[adj[node][i]]){
                               return 0;
                           }
                       }
                   }
               }
           }}
           return 1;
       }
       
};



/////DFS;


class Solution {
  public:
  
      vector<vector<int>> constructGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(const auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }

    bool checkBip(int node,vector<vector<int>> &adj,vector<int> &color){
        
        
        for(int i= 0; i< adj[node].size();i++){
            if(color[adj[node][i]] == -1){
                color[adj[node][i]] = (color[node]+1)%2;
                if(!checkBip(adj[node][i],adj,color)){
                    return 0;
                }
            }else{
                if(color[node] == color[adj[node][i]]){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj = constructGraph(V, edges);
        vector<int>color(V,-1);
       for(int i = 0;i<V;i++){
           if(color[i] == -1){
               color[i] = 0;
               if(!checkBip(i,adj,color)){
                   return 0;
               }
           }
       }
       return 1;
      
      
      
       }

       
};