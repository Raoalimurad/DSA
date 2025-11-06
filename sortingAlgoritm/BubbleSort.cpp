// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   int arr[] = {9,7,3,1,10,0};
   int n = sizeof(arr)/sizeof(arr[0]);
   for(int i = 0; i<n-1;i++){
       bool swapped = false; ///ya islia agar array best  case me phley se hi sort ho to hume bar bar check karny hi need nahi
       for(int j = 0; j<n-i-1;j++){
           if(arr[j]>arr[j+1]){
               swapped = true;
               swap(arr[j],arr[j+1]);
           }
       }
       if(!swapped) break;
   }
for(int i = 0; i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}