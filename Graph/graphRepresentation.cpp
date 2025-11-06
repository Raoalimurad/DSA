#include <iostream>
#include <vector>
using namespace std;
/// adjacency matix using here

int main() {
    // UNDIRECTED UNWEIGHTED GRAPH
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<bool>> adjMat(vertex, vector<bool>(vertex, 0));
    
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    // Optional: Print the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//case 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // UNDIRECTED WEIGHTED GRAPH
    int vertex, edges;
    cin >> vertex >> edges;
   cout<<"now put edges";
    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));
    
    for (int i = 0; i < edges; i++) {
        int u, v , weight;
        cin >> u >> v >> weight;
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }

    // Optional: Print the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//case 3
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // DIRECTED WEIGHTED GRAPH
    int vertex, edges;
    cin >> vertex >> edges;
   cout<<"now put edges";
    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));
    
    for (int i = 0; i < edges; i++) {
        int u, v , weight;
        cin >> u >> v >> weight;
        adjMat[u][v] = weight;
       
    }

    // Optional: Print the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


//case 4
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // DIRECTED  GRAPH
    int vertex, edges;
    cin >> vertex >> edges;
   cout<<"now put edges";
    vector<vector<bool>> adjMat(vertex, vector<bool>(vertex, 0));
    
    for (int i = 0; i < edges; i++) {
        int u, v ,;
        cin >> u >> v ;
        adjMat[u][v] = 1;
       
    }

    // Optional: Print the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
