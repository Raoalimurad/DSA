class Solution {
public:
    bool isCheckCycle(vector<vector<int>> &adj, int node, vector<bool> &visited, int parent) {
        visited[node] = true;

        for(int i : adj[node]) {
            if(!visited[i]) {
                if(isCheckCycle(adj, i, visited, node)) {
                    return true;
                }
            }
            else if(i != parent) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> constructGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(const auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj = constructGraph(V, edges);
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(isCheckCycle(adj, i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
