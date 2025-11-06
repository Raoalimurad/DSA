=-0987654321`    Template for C++

class Solution {
  public:
   void DFS(int node,int parent,vector<int> adj[],vector<int> &disc,vector<int> &low,vector<bool> &visited,int &timer,vector<bool> &artPoint){
      disc[node] = low[node] = timer;
       visited[node] = 1;
       int child = 0;
       for(int j= 0; j<adj[node].size();j++){
           int neib = adj[node][j];
           if(neib == parent){
               continue;
           }else if(visited[neib]){
               low[node] = min(low[node],disc[neib]);
               
           }else{
               child++;
               timer++;
               DFS(neib,node,adj,disc,low,visited,timer,artPoint);
               if(disc[node]<=low[neib] && parent != -1){
                   artPoint[node] = 1;
               }
               low[node] = min(low[node],low[neib]);
               
           }
           
       }
       if(child>1 && parent == -1){ //ya conditon sirf starting ndoe kalia hy
           artPoint[node] = 1;
       }
   }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<bool>artPoint(V,0) ;//because koi bi node ak se ziada bar articulaton point ho sakta hy
        vector<int>disc(V,0);
        vector<int> low(V,0);
        vector<bool> visited(V,0); 
        int timer = 0;
        
        DFS(0,-1,adj,disc,low,visited,timer,artPoint);
        
        
        vector<int> ans;
        for(int i= 0; i<V;i++){
            if(artPoint[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0){
            ans.push_back(-1);
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};