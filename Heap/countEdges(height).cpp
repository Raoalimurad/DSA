
#include <iostream>
using namespace std;
int main() {
  int arr[] = {1,2,3,4,5,6,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<n;
  int ans = 0;
  while(n >1){
      n = n/2;
      ans++;
  }
  cout<<ans;

    return 0;
}