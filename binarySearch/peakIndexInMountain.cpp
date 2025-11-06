// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2,4,6,8,10,8,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int st = 1; 
    int end = n-2;
    while(st<=end){
        int mid = st+(end-st)/2; ///assume mid is 10
        //// 8<10>8 yani mid se left or right dono is se chotty ho jo peak hoga
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            cout<<mid ;//// 10 print hoga;
            break;
            ///agar pick nahi ho check kia uska left us se chotta hy yani incraseing order chal raha yani to mid+1 kardo
        }else if(arr[mid-1]<arr[mid]){
            st = mid+1;
        }else{
            ///yaha decreasing ho raha hoga to islia mid-1 karka hume waha ana jahn dono left rihgt choty ho
            end = mid-1;
        }
    }

    return 0;
}