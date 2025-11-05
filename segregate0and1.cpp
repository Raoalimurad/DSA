// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> arr = {1,0,1,0,1,0};
    int n = arr.size();
    int st = 0, end = n-1;
    while(st<=end){
        if(arr[st] == 0){
            st++;
        }else{
            if(arr[end] == 0){
                swap(arr[st],arr[end]);
            }else{
                end --;
            }
        }
    }
    
for(int x:arr){
    cout<<x<<" ";
}
    return 0;
}