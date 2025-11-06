// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int arr1[3][3] = {{2,3,5},{6,8,4},{10,11,12}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    for(int i = 0; i<rows;i++){
        for(int j = 0; j<cols;j++){
            arr[i][j] +=arr1[i][j];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}