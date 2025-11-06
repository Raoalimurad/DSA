
#include <iostream>
#include <queue>
using namespace std;
int main() {
  priority_queue<int,vector<int>,greater<int>>minHeap;
  int arr[] = {4,3,2,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i = 0;i<n;i++ ){
      minHeap.push(arr[i]);
  }
  int cost = 0;
  while(minHeap.size()>1){
      int rope = minHeap.top();
      minHeap.pop();
      rope+=minHeap.top();
      minHeap.pop();
      cost+=rope;
      
      minHeap.push(rope);
  }
  cout<<cost;
}  