// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {1,4,6,8,10,45};
    int n = arr.size();
    int x = 13;
    for(int i = 0; i< n-2;i++){
        int ans = x-arr[i];
        int st = i+1,end = n-1;
        while(st<end){
            if(arr[st]+arr[end] == ans){
                cout<<"melgya";
                break;
            }else if(arr[st]+arr[end]>ans){
                end--;
            }else{
                st++;
            }
        }
    }

    return 0;
}