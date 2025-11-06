//Position this line where user code will be pasted.
class Solution {
  public:
   void topological(int node,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &s){
       
       visited[node] = 1;
       for(int j = 0; j<adj[node].size();j++){
           if(!visited[adj[node][j]]){
               topological(adj[node][j],adj,visited,s);
           }
       }
       s.push(node);
       
   }
   
   void DFS(int node,vector<vector<int>> &adj2,vector<bool> &visited){
       visited[node] = 1;
       for(int j = 0; j<adj2[node].size();j++){
           if(!visited[adj2[node][j]]){
               DFS(adj2[node][j],adj2,visited);
           }
       }
   }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        
        
        /////topological sort
        
        stack<int> s;
        vector<bool> visited(V,0);
        for(int i = 0; i<V;i++){
            if(!visited[i]){
                topological(i,adj,visited,s);
            }
        }
        
        
        
        ///reverse/transpose the graph
        
        vector<vector<int>> adj2(V);
        for(int i = 0; i<V;i++){
            for(int j = 0; j<adj[i].size();j++){
                int u = i;
                int v = adj[i][j];
                adj2[v].push_back(u);
            }
        }
        
        ///pop the element from stack
        /// not visited so SCC++ AND APPY DFS
        
        //// make visited arry to unvisited
        for(int i = 0; i<V;i++){
            visited[i] = 0;
        }
        int SCC = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visited[node]){
                SCC++;
                DFS(node,adj2,visited);
            }
            
        }
        
        
        
       return SCC; 
        
        
    }
};
///time complexity
///V+E   V+E,      V+E   = V+E
// Topologicalsort   reverseEdges     emptyQueueDFS

//space complexity
 //V+E