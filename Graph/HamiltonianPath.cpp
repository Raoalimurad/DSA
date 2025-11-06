class Solution {
  public:
    bool DFS(int node,vector<int> adj[],vector<bool> &visited,int &count,int N){
        visited[node] = 1;
        count++;
        if(count == N){
            return 1;
        }
        for(int j = 0; j<adj[node].size();j++){
            if(!visited[adj[node][j]] && DFS(adj[node][j],adj,visited,count,N)){
                return 1;
            }
        }
        visited[node] = 0;
        count --;
        return 0;
        
    }
    bool check(int N, int M, vector<vector<int>> edges) {
        // code here
        vector<int> adj[N+1];
        for(int i = 0; i< M ;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(N+1,0);
        int count = 0;
        for(int i = 0; i<N;i++){
            if(DFS(i,adj,visited,count,N)){
                return 1;
            }
        }
        return 0;
    }
};
