
#include <iostream>
#include<vector>
using namespace std;
void Heapify(vector<int>& arr,int index,int n){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left< n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != index){
        swap(arr[index],arr[largest]);
        Heapify(arr,largest,n);
    }
}
int main() {
  vector<int> a = {10,8,9,7,5};
  vector<int> b = {1,4,3,12,19,30};
  int n = a.size();
  int m = b.size();
  vector<int> ans;
  for(int i = 0; i< n;i++){
      ans.push_back(a[i]);
  }
  for(int i = 0 ; i< m;i++){
      ans.push_back(b[i]);
  }
  int N = ans.size();
  for(int i =N/2-1;i>=0;i--){
      Heapify(ans,i,N);
  }
  for(int i = 0; i<N;i++){
      cout<<ans[i]<<" ";
  }
    return 0;
}