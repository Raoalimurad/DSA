/// DFS //////
class Solution {
  public:
   ////build graph
   vector<vector<int>> buildAdj(int V, vector<vector<int>>& edges){
       vector<vector<int>> adj(V);
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);
       }
       return adj;
   }
   void DFS(int node,vector<vector<int>>& adj,vector<bool> &visited,stack<int> &s){
       visited[node] = true;
       for(int x:adj[node]){
           if(!visited[x]){
               DFS(x,adj,visited,s);
           }
       }
       s.push(node);
   }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
     vector<vector<int>> adj =   buildAdj(V,edges);
     
       vector<bool> visited(V,0);
       stack<int>s;
       for(int i = 0 ; i<visited.size();i++){
           if(!visited[i]){
               DFS(i,adj,visited,s);
           }
       }
       vector<int> ans;
       while(!s.empty()){
           ans.push_back(s.top());
           s.pop();
       }
       return ans;
    }
};