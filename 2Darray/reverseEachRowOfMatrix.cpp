// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int arr[2][4] = {{5,8,3,9},{6,2,8,4}};
    int rows = sizeof(arr)/sizeof(arr[0]);
     for(int i = 0; i<rows;i++){
         int col = sizeof(arr[i])/sizeof(arr[i][0]);
         int st = 0, end = col-1;
         while(st<end){
             swap(arr[i][st],arr[i][end]);
             st++;
             end--;
         }
     }
     for(int i = 0; i<rows;i++){
         for(int j = 0;j<4;j++){
             cout<<arr[i][j]<<" ";
         }
         cout<<endl;
     }
    return 0;
}