///for sparse graph

class Solution {
    ///find ultimate parents
    int ultimateParent(int node, vector<int> &parent) {
        if (node == parent[node]) {
            return node;
        }
        /// path compression
        parent[node] = ultimateParent(parent[node], parent);
        return parent[node];
    }
    
    void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = ultimateParent(u, parent);
        int pv = ultimateParent(v, parent);
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
     
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int,int>> adj[V];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> parent(V);
        vector<int> rank(V, 0);
        /// initially ultimate parent is itself
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
       
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;              
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {   // ✅ corrected
                int v = adj[i][j].first;
                int w = adj[i][j].second;
                q.push({w, {i, v}});
            }
        }

        int cost = 0;
        while (!q.empty()) {
            int w = q.top().first;
            int u = q.top().second.first;
            int v = q.top().second.second;
            q.pop();
            if (ultimateParent(u, parent) != ultimateParent(v, parent)) { // ✅ spelling fixed
                cost += w;
                unionByRank(u, v, parent, rank);  // ✅ semicolon fixed
            }
        }   
        return cost;
    }
};
