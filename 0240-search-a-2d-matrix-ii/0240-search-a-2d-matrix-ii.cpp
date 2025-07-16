class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int  row = 0;
        int col = m-1;
        if (matrix.empty() || matrix[0].empty()) return false;
        while(row <n && col >= 0) {
            if(matrix[row][col] == target ) return true;
            else if(matrix[row][col] < target ) row++;
            else col--;
        }
        return false ;
    }
};

// this is a very important problem that will teach y how to think out of the box in the binary search , here isthe solution 