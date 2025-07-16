class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m  = matrix[0].size();
        int low = 0;
        int high = n*m -1;
        while(low <= high ) {
            int mid = (low + high) / 2;
            int row = mid/m;
            int col = mid % m ;
            if(matrix[row][col] == target )  return true;
            else if(matrix[row][col] < target ) low = mid+1;
            else high = mid - 1;
        }
        return false ;
    }
   
};

 // this is a problem of concept of flatten a 2d matrix ton a 1d matrix or rather should say i will be doing  changes the 1 d coordinates to 2d coordinate  s