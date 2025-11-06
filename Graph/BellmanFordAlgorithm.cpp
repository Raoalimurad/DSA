// User function Template for C++
// time complexity is (V-1 * e) + e = V+e; and in best case E;
 

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8); ////distance
        dist[src] = 0;  // ya zero islia hy kud se kud taka distance 0 hotta hy 
        int e = edges.size();
        
        for(int i = 0; i<V-1;i++){
            bool flag = 0;
            for(int j = 0 ; j<e;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                if(dist[u] == 1e8){
                    continue;
                }
                if(dist[u]+weight < dist[v]){
                    flag = 1;
                    dist[v] = dist[u]+weight;
                }
            }
            /// ya islia lagaya hy ka agar v-1 time se phley hi hume shortest path mel gya to exist kar jao ap v-1 tak na check karo
            if(!flag){
                return dist;
            }
            
        }
        
        //// detect the cycle
        
         for(int j = 0 ; j<e;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                if(dist[u] == 1e8) continue;
                if(dist[u]+weight < dist[v]){
                    vector<int> ans;
                    ans.push_back(-1);
                    return ans;
                }
            }

        return dist;
    }
};
