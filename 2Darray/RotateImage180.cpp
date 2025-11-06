#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int times = 2; // because 90° + 90° = 180°

    while (times > 0) {
        int n = matrix.size();

        // Step 1: Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        times--; // decrease rotation count
    }

    cout << "Matrix after 180 degree rotation:" << endl;
    for (auto row : matrix) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
