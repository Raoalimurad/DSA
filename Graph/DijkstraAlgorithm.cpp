// User Function Template
/// dense grpah kalia use hotta hy 
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //// make adjcanceny list
        vector<pair<int,int>> adj[V];
        int N = edges.size();
        for(int i = 0; i< N; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back(make_pair(v,weight));
            adj[v].push_back(make_pair(u,weight));
        }
        
        ////// dijkstra algorithm
        vector<bool>explore(V,0);
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        
        ///select a vertice  which is not explore yet and  its distance value is minium among all the unexplored vertices
      
       int count = V;
      //0(V) SO OVERALL OUTER PER V+INNER ME (V+(V-1)) SO ISY V BOL LO V*V = V2
       while(count --){
        int node = -1 , value = INT_MAX;
         //0(v)
        for(int i = 0; i<V;i++){
            if(!explore[i] && dist[i] < value ){
                node = i;
                value = dist[i];
            }
        }
        if(node == -1) break;
        explore[node] = 1;
        ////relax the edges  v-1 time assume beacuse agar complete graph bi hoto v-1 vertices hogye uski neighbours
        for(int i = 0; i<adj[node].size();i++){
            int neighbour = adj[node][i].first;
            int weight = adj[node][i].second;
            if(!explore[neighbour] && dist[node]+weight<dist[neighbour]){
                dist[neighbour] = dist[node]+weight;
            }
        }
        
       }
       return dist;
        
    }
};
//Time Complexity = O(V^2 + E)
//Space Complexity = O(V + E) (adjacency list + dist + visited array)







//UISNG PREORITY QUEUE
//space complexity V+E 

//time complexity  = ELOGE + ELOGE  = E LOG E  THEN COMPLTE GRPAH HOTO ELOGV HOTJAY hy 

/// ya method sparse graph kalia hotta hy 
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //// make adjcanceny list
        vector<pair<int,int>> adj[V];
        int N = edges.size();
        for(int i = 0; i< N; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back(make_pair(v,weight));
            adj[v].push_back(make_pair(u,weight));
        }
        
        ////// dijkstra algorithm
        vector<bool>explore(V,0);
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        
        ///select a node which is not explore yet and distance value is minium
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          pq.push({0,src});///ya make_pair(0,src) dono same hi han
          
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
                 if(!explore[neighbour] && dist[node]+weight < dist[neighbour]){
                     dist[neighbour] = dist[node]+weight;
                     pq.push({dist[neighbour],neighbour});
                 }
              }
          }

   return dist;
    
    }

};
