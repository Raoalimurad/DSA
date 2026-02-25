// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
#include<vector>
using namespace std;
bool checkCycle(vector<vector<int>> adj,vector<bool> &visited){
    visited[0] = 1;
    queue<pair<int,int>> q;
    q.push({0,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int neib:adj[node]){
            ///ignore parent
            if(parent == neib) continue;
            //if neib visited found;
            if(visited[neib]) return true;
            
            //make visited or push into queue
            visited[neib] = true;
            q.push({neib,node});
        }
    }
    return 0;
}
int main() {
    vector<vector<int>> adj = {
    {1, 2},   // 0
    {0, 2},   // 1
    {0, 1}    // 2
};
   int V = adj.size();
   vector<bool>visited(V,false);
 bool isCycle = checkCycle(adj,visited);
   if(isCycle){
       cout<<"cycle is present";
   }
    return 0;
}
////agar graph disconnect hoto

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfsCycle(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<pair<int,int>> q;
    visited[start] = true;
    q.push({start, -1});   // node, parent

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neib : adj[node]) {

            // ignore parent
            if (neib == parent) continue;

            // visited neighbour → cycle
            if (visited[neib]) return true;

            visited[neib] = true;
            q.push({neib, node});
        }
    }
    return false;
}

bool checkCycle(vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);

    // IMPORTANT: check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (bfsCycle(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {

    // cycle present
    vector<vector<int>> adj = {
        {1,2},   // 0
        {0,2},   // 1
        {0,1}    // 2
    };

    if (checkCycle(adj, adj.size()))
        cout << "Cycle is present";
    else
        cout << "No cycle";

    return 0;
}
