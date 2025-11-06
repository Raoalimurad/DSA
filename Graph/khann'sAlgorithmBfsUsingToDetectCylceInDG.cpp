class Solution {
  public:
   vector<vector<int>> buildAdj(int V, vector<vector<int>>& edges){
       vector<vector<int>> adj(V);
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);
       }
       return adj;
   }
    
       
   
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj =   buildAdj(V,edges);
        vector<int>inDegree(V,0);
        for(int i = 0; i<V;i++){
            for(int j = 0; j< adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i<inDegree.size();i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0; i<adj[node].size();i++){
                inDegree[adj[node][i]]--;
                if(!inDegree[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
            
        }
        int count = ans.size();
        return count !=V;
    } 
};