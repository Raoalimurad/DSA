class Solution {
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

        // Step 2: Required arrays
        vector<int> isMST(V, 0);
        vector<int> parent(V, -1); // for MST printing (optional)

        // Step 3: Priority Queue {weight, {node, parent}}
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;

        pq.push({0, {0, -1}});
        int cost = 0;

        while (!pq.empty()) {
            int w    = pq.top().first;
            int node = pq.top().second.first;
            int par  = pq.top().second.second;
            pq.pop();

            if (!isMST[node]) {
                isMST[node] = 1;
                cost += w;
                parent[node] = par;

                for (int j = 0; j < adj[node].size(); j++) {
                    int v  = adj[node][j].first;
                    int wt = adj[node][j].second;
                    if (!isMST[v]) {
                        pq.push({wt, {v, node}});
                    }
                }
            }
        }

        return cost;
    }
};
