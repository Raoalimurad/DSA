class Solution {
public:
  bool isValid(vector<int> & weights,int days,int maxAllowedCapacity){
     int count  = 1,capacity = 0;
     for(int i = 0; i<weights.size();i++){
        if(weights[i]+capacity<=maxAllowedCapacity){
            capacity +=weights[i];
        }else{
            count++;
            capacity = weights[i];
        }
     }
     return count<=days?true:false;
  }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxVal = INT_MIN, sum = 0;
        for(int i = 0; i<weights.size();i++){
            sum +=weights[i];
            maxVal = max(maxVal,weights[i]);
        }

        int st = maxVal,end = sum;
        int ans = -1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(isValid(weights,days,mid)){
              ans = mid;
              end =  mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};