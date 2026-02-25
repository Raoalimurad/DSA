class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ///MAKE ADJANCENY LIST
        int N = flights.size();
        vector<pair<int,int>>adj[n];
        for(int  i = 0; i<N;i++){
            int u = flights[i][0];
            int v = flights[i][1];
             int w = flights[i][2];
             adj[u].push_back(make_pair(v,w));
        }
        vector<int>distance(n,INT_MAX);
        distance[src] = 0;
        queue<pair<int,int>>q;
        q.push(make_pair(src,0));
        int step = 0;
        while(!q.empty() && step<=k){
            int Total = q.size();
            while(Total--){
             int u = q.front().first;
            int w = q.front().second;
            q.pop();
            for(pair<int,int>&p:adj[u]){
                int v = p.first;
                int cost = p.second;
                if(distance[v]>w+cost){
                    distance[v] = w+cost;
                    q.push(make_pair(v,w+cost));
                }
            }   
            }
            step++;
        }
        if(distance[dst] == INT_MAX){
            return -1;
        }
        return distance[dst];
    }
};