class Solution {
  public:
   void makeDFS(vector<vector<int>> &adj,int s,vector<bool> &visit,vector<int> &res){
       visit[s] = true;
       res.push_back(s);
       for(int x:adj[s]){
           if(!visit[x]){
               makeDFS(adj,x,visit,res);
           }
       }
   }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V  = adj.size();
        vector<bool>visit(V,false);
        vector<int> res;
        makeDFS(adj,0,visit,res);
        return res;
    }
};
//USING STACK

vector<int> dfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;
    stack<int> st;

    st.push(0); // start from node 0

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            res.push_back(node);

            // Push all unvisited adjacent nodes
            // Reverse loop so that left nodes come out first (to match recursion order)
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }

    return res;
}
