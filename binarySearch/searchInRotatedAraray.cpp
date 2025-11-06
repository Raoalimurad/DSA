// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int arr[] = {6,7,0,1,2,4,5};
int target = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    int st = 0,end = n-1;
    while(st<=end){
       int mid = st+(end-st)/2;
       if(arr[mid] == target){
           cout<<mid;
           break;
       }else if(arr[0]<=arr[mid]){
           if(arr[st]<=target && target>arr[mid]){
               end = mid-1;
           }else{
               st = mid+1;
           }
       }else{
           if(arr[mid]<target && target<=arr[end]){
               st=mid+1;
           }else{
               end = mid-1;
           }
           
           
           
           
       }
       
       
       
       
       
       
       
       
    }

    return 0;
}