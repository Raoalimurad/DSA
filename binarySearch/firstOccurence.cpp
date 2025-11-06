// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int target){
    int st = 0, end = n-1;
    int occurence = -1;
    while(st<=end){
        int mid = st+(end-st)/2;
       if(arr[mid] ==  target){
           occurence = mid;
           end = mid-1;
       }else if(target>arr[mid]){
          st = mid+1;
       }else{
           end = mid-1;
       }
    }
    
    return occurence;
}
int main() {
    int arr[] = {1,1,1,2,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 2;
    int ans = binarySearch(arr,n ,target);
    cout<<ans;

    return 0;
}