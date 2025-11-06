
#include <iostream>
#include<vector>
#include <queue>
using namespace std;
int main() {
  priority_queue<int>H;
  vector<int> arr = {2,4,6,8,10};
  for(int i = 0; i< arr.size();i++){
      H.push(arr[i]);
  }
  int maxChoc = 0;
  int A = 5;
  while(A && (!H.empty())){
      maxChoc+=H.top();
     
      if(H.top()/2){
          H.push(H.top()/2);
      }
      H.pop();
      A--;
  }
  cout<<maxChoc;
}