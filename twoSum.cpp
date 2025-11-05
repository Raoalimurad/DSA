// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> arr = {2,7,11,15,27};
    int n = arr.size();
    int st = 0, end = n-1;
    int target = 9;
    while(st<=end){
        if(arr[st]+arr[end] == target){
            cout<<arr[st]<<" ";
            cout<<arr[end];
            break;
        }else if(arr[st]+arr[end]<target){
            st++;
        }else{
            end--;
        }
    }

    return 0;
}