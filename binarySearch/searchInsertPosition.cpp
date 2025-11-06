class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n  = nums.size();
        int st = 0, end = n-1;
        int index = n ;//// ya is waja se n lia hy deko assume array 1,2,3,4 or wo bolee 5 kahn aye ga to wo zahir se bad n ki jaga per yae ga

        while(st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]<target){
                st = mid+1;
            }else{
                index = mid; // ya deko agar array 1,4,6,8,10,14,16 or mid ayia 8 or target howa 7 to hume jab nums[mid] apka target se bara hoto usy index me store karna hotta hy wo islia ka 7 kahn aye ga 3 index per jahn 8 hy agar me isy store na karo to end = mid-1 me wo index to waste ho jae gte
                end = mid-1;
            }
        }
        return index;

    }
};