class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& pre) {
        // Code here
        ///make adjacency list
        vector<int>adj[N];
        for(int i = 0; i<P;i++){
            int u = pre[i].first;
            int v = pre[i].second;
            adj[v].push_back(u);
        }
        
        ///apply BFS khann's algorithm
        vector<int>inDegree(N,0);
        for(int i = 0; i<N;i++){
            for(int j = 0;j<adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }
        ///check which node degree is 0 put in queue
        queue<int>q;
        for(int i = 0; i<N;i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int neib :adj[node]){
                inDegree[neib]--;
                if(inDegree[neib] ==0){
                    q.push(neib);
                }
            }
        }
       ////ya islisa agar count n ka equal ajee to matlab hum task complete kar sakty hy or cylcle bi nahi hy 
        return N == count ? true:false;
        
        
        
        
        
        
        
        
        
    }
};