class Solution {
  public:
  void DFS(int node,vector<int> adj[],vector<bool> &visited){
      visited[node] = 1;
      for(int i = 0; i<adj[node].size();i++){
          if(!visited[adj[node][i]]){
              DFS(adj[node][i],adj,visited);
          }
      }
  }
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        vector<int> Degree(V,0);
        ///calculate degree
        int odd = 0;
       for(int i = 0; i<V;i++){
           Degree[i] = adj[i].size();
           if(Degree[i]%2){
               odd++;
           }
       }
       
       if(odd !=2 && odd != 0){
           return 0;
       }  
       vector<bool>visited(V,0);
       for(int i = 0; i<V;i++){
           if(Degree[i]){
               DFS(i,adj,visited);//// ya lagana ka matlab ya ka waha se start karo jahan ki degree exist karty ho 
               break;
           }
       }
       
       //if non zero still not visited then return 0;;
       for(int i = 0; i<V;i++){
           if(Degree[i] && !visited[i]){
               return 0;
           }
       }
       
       //euler cirucit return 2;
       if(odd == 0){
           return 2;
       }
       ///euler path
       return 1;
       
       
       
    }
};
//time complexity v+e space v