// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    int maxSum = 0;
    int row = -1;
    for(int i = 0; i<rows;i++){
        int sum = 0;
        for(int j = 0; j<cols;j++){
           sum+=arr[i][j];
        }
        if(sum>maxSum){
            maxSum = sum;
            row = i;
        }
    }
    cout<<maxSum<<" ";
    cout<<row;

    return 0;
} 