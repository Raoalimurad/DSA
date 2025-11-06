#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = mat.size();               
    int cols = mat[0].size();    
    int k = 4;
    vector<pair<int,pair<int,int>>>arr;
    for(int i = 0; i< rows;i++){
        arr.push_back(make_pair(mat[i][0],make_pair(i,0)));
    }
    
 priority_queue<
  pair<int,pair<int,int>>,
  vector<pair<int,pair<int,int>>>,
  greater<pair<int,pair<int,int>>>
  >pq(arr.begin(),arr.end());
  
  int ans;
  int i,j;
  pair<int,pair<int,int>>Element;
  while(k--){
      Element = pq.top();
      ans = Element.first;
       pq.pop();
      i = Element.second.first;
      j = Element.second.second;
      if(j+1<cols){
          pq.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
      }
  }
  
  cout<<ans;
  
  
    return 0;
}
