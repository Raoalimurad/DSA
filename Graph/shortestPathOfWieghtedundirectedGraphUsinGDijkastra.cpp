class Solution {
  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        //C ode here
        vector<pair<int,int>> adj[N+1];
        for(int i = 0; i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        /////dijkastra alogrithm;
        vector<bool>explore(N+1,0);
        vector<int> dist(N+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>parent(N+1,-1);
        pq.push({0,1});
        dist[1] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            if(explore[node]){
                continue;
            }
            explore[node] = 1;
            for(int j = 0; j<adj[node].size();j++){
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                
                if(!explore[neighbour] && dist[node]+weight < dist[neighbour] ){
                    dist[neighbour] = dist[node]+weight;
                    pq.push({dist[neighbour],neighbour});
                    parent[neighbour] = node;
                }
                
                
            }
        }
        
        vector<int>path;
        int dest = N;
        if(parent[N] == -1){
            path.push_back(-1);
            return path;
        }
        
        while(dest != -1){
            path.push_back(dest);
            dest = parent[dest];
        }
        path.push_back(dist[N]);
        reverse(path.begin(),path.end());
        return path;
        
        
        
    }
};