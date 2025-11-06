// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<vector<int> > mat = {{3,7,9,17},{6,8,3,8},{4,11,2,5},{2,5,1,9}};
    int row = mat.size();
    int col = mat[0].size();
    bool check = true;
    for(int i = 0; i<col;i++){
        if(check){
            for(int j = 0;j<row;j++){
                cout<<mat[j][i]<<" ";
            }
            check = false;
        }else{
            for(int j=row-1;j>=0;j--){
                cout<<mat[j][i]<<" ";
            }
            check = true;
        }
        
    }

    return 0;
}