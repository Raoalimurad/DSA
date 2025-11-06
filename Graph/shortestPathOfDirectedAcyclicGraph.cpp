// User function Template for C++
class Solution {
  public:
  void DFS(int node,vector<pair<int,int>> adj[],vector<int> &visited,stack<int> &s1){
      
      visited[node] = 1;
      for(int j = 0; j<adj[node].size();j++){
          if(!visited[adj[node][j].first]){
              DFS(adj[node][j].first,adj,visited,s1);
          }
      }
      s1.push(node);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        
        ///// create adjacency list create karo
        
        vector<pair<int,int>> adj[V];
        for(int i = 0 ; i< E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back(make_pair(v,weight));
        }
        
        
        
        //// topological sort 
        
        stack<int>s1;
         vector<int>visited(V,0);
         DFS(0,adj,visited,s1);
        
        vector<int>dist(V,INT_MAX);
         dist[0] = 0;
        ///stack empty
        
        while(!s1.empty()){
            int node = s1.top();
             s1.pop();
            for(int j = 0; j<adj[node].size();j++){
           
            //look at the neighbours
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                dist[neighbour] = min(dist[neighbour],weight+dist[node]);
            }
            
            
        }
        
        ///-1 for those values jo hum reach nahi kar sakee
        for(int i = 0; i<dist.size();i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        
        return dist;
        
        
        
        
        
        
    }
};
