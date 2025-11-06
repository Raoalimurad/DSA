// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int V = dist.size();
        
        for(int k = 0 ; k<V;k++){
            
            for(int i = 0; i<V;i++){
                
                
                for(int j = 0; j< V;j++){
                    
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
    }
};

.///check negative cycle 
///ya digonal check kar rahahy waha negative value to nai
        for(int i = 0; i < V; i++){
            if(dist[i][i] < 0){
                cout << "Graph contains a negative weight cycle\n";
                return;
            }
        }