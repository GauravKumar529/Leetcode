
class Solution {
public:
    int findPeak(vector<int>& arr) {
        int maxIdx = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }
        return maxIdx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int midRow = (low + high) / 2;
            int col = findPeak(mat[midRow]);

            int curr = mat[midRow][col];
            int up = (midRow - 1 >= 0) ? mat[midRow - 1][col] : -1;
            int down = (midRow + 1 < n) ? mat[midRow + 1][col] : -1;

            if (curr > up && curr > down) {
                return {midRow, col};
            } else if (down > curr) {
                low = midRow + 1;
            } else {
                high = midRow - 1;
            }
        }

        return {-1, -1}; // Shouldn't reach here for valid input
    }
};
