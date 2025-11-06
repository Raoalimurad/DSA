class Solution {
  public:
   vector<vector<int>> buildAdj(int V, vector<vector<int>>& edges){
       vector<vector<int>> adj(V);
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);
       }
       return adj;
   }
    bool DFS(int node,vector<vector<int>> adj,vector<bool> &path,vector<bool> &visited){
        path[node] = 1;
        visited[node]  = 1;
        
        for(int i = 0; i<adj[node].size();i++){
            if(path[adj[node][i]] == 1){
                return true;
            }
            
            if(visited[adj[node][i]] == 1){
                continue;
            }
            if(DFS(adj[node][i],adj,path,visited)){
                return 1;
            }
        }
        
        
        
        
        
        
        
        path[node] = 0;
        return 0;
    }
   
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj =   buildAdj(V,edges);
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        for(int i = 0; i<V;i++){
            if(!visited[i]){
                if(DFS(i,adj,path,visited)){
                    return 1;
                }
            }
        }
        return 0;
        
    }
};