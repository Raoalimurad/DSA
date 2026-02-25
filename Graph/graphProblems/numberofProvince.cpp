class Solution {
public:
 void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        for(int neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        //make adjanceny list
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n;j++){
             if(isConnected[i][j] == 1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
             }
            }
        }

        vector<bool>visited(n,false);
        int province = 0;
        for(int i = 0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited);
            province++;
        }
        }
        return province;
    }
};