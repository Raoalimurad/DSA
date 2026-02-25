class Solution {
public:
  int r,c;
  int row[4] = {-1,1,0,0};
  int col[4] = {0,0,-1,1}; 
  bool valid(int i,int j){
    return i>=0&&i<r && j>=0&&j<c;
  }
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int,int>>q;
        int fresh= 0;
        ///first put all rotten oranges in queue
        for(int i = 0; i<r;i++){
            for(int j = 0; j<c;j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
         int time = 0;
         while(!q.empty() ){
            time++;
            int totalElem = q.size();
            while(totalElem--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0;k<4;k++){
                    if(valid(i+row[k],j+col[k])&& grid[i+row[k]][j+col[k]] == 1){
                        grid[i+row[k]][j+col[k]] = 2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
            }
         }

         for(int i = 0; i<r;i++){
            for(int j = 0; j<c;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
         }
         
         return time-1;

    }
};