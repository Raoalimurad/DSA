class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        int st = 0 , end = N*M-1;
        int row_Index,col_Index;
        while(st<=end){
            int mid = st+(end-st)/2;
            row_Index = mid/M;
            col_Index = mid%M;
            if(matrix[row_Index][col_Index] == target){
                return 1;
            }else if(matrix[row_Index][col_Index]<target){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return 0;
    }
};