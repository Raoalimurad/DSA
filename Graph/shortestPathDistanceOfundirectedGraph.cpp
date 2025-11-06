class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int N = adj.size();
        vector<int> visited(N,0);
        vector<int>dist(N,-1);
        queue<int>q;
        visited[src] = 1;
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j = 0; j<adj[node].size();j++){
                if(visited[adj[node][j]]){
                    continue;
                }
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
                dist[adj[node][j]] = dist[node]+1;
            }
        }
        return dist;
    }
};