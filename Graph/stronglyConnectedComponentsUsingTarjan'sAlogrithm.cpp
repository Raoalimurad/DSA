// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    void DFS(int node,vector<int> adj[],vector<bool> &visited,vector<int> &disc,vector<int> &low,stack<int> &s,vector<bool> &InStack,int &timer,vector<vector<int>> &ans){
        visited[node] = 1;
        disc[node] = low[node] = timer;
        s.push(node);
        InStack[node] = 1;
        for(int j = 0; j<adj[node].size();j++){
            int neib = adj[node][j];
            if(!visited[neib]){
                timer++;
                DFS(neib,adj,visited,disc,low,s,InStack,timer,ans);
                low[node] = min(low[node],low[neib]);
            }else{
                //first check it is present in stack if it is visited
                if(InStack[neib]){
                    low[node] = min(low[node],disc[neib]);
                }
            }
        }
        ///condition OF SCC
        if(disc[node] == low[node]){
           vector<int> temp;
           while(!s.empty() && s.top() != node){
               temp.push_back(s.top());
               InStack[s.top()] = 0;
               s.pop();
               
           }
           temp.push_back(node);
           InStack[node] = 0;
           s.pop();
           sort(temp.begin(),temp.end());
           ans.push_back(temp);
           
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        // code here
        
        vector<vector<int>> ans;
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V,0);
        stack<int>s;
        vector<bool> InStack(V,0);
        int timer = 0;
        for(int i = 0; i<V;i++){
            if(!visited[i]){
                 DFS(i,adj,visited,disc,low,s,InStack,timer,ans);
            }
        }
       sort(ans.begin(),ans.end()); ///qk sort manga hy islia sort kia 
        return ans;
    }
};
//time complexity V+E;