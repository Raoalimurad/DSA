class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src,int des) {
        // code here
        int N = adj.size();
        vector<int> visited(N,0);
        vector<int>dist(N,-1); ///no need of distance qk hum path find kar rhay source to des
        vector<int>parent(N,-1);
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
                dist[adj[node][j]] = dist[node]+1;///deko yaha per ap distance nahi path find kar rahy ho soruce to destination distance walee ko hata bi sakty ho
                parent[adj[node][j]] = node;
            }
        }
        vector<int> path;
        while(des != -1){
            path.push_back(des);
             des = parent[des];
        }
        reverse(path.begin(),path.end())
        return path;
    }
};