// Online C++ compiler to run C++ program online
#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
bool isPossible(vector<int> stalls,int cow,int d){
    int count = 1; 
    int lastPos = stalls[0];
    for(int i = 1; i<stalls.size();i++){
        if(stalls[i] - lastPos>=d){
            count++;
            lastPos = stalls[i];
            if(count == cow) return true;
        }
    }
    return false;
}
int main() {
     vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    sort(stalls.begin(),stalls.end());
    int end = stalls.back()-stalls.front();
    int st = 1 ;
    int ans = 0;
   while(st<=end){
       int mid = st+(end-st)/2;
       if(isPossible(stalls,cows,mid)){
           ans = mid;
           st = mid+1;
       }else{
           end = mid-1;
       }
   }
    
    cout<<ans;
    return 0;
} 