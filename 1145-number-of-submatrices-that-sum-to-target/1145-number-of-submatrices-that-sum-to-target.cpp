class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> pre(r, vector<int> (c+1, 0));

        //prefix matrix 
        for(int i  = 0 ; i < r;i++){
            for(int  j = 0 ; j<c;j++){
                pre[i][j+1] = pre[i][j] + matrix[i][j];
            }
        }
        int  cnt =0;
        for(int starting_col = 0 ;starting_col< c;starting_col++){
            for(int j = starting_col ;j< c ;j++){
                unordered_map<int, int> mpp;
                mpp[0] = 1;
                int sum =0;
                for(int row = 0; row < r; row++){
                    sum += (pre[row][j+1] - pre[row][starting_col]);
                    int ch = sum  - target ;
                    if(mpp.find(ch ) != mpp.end())  cnt += mpp[ch];
                    mpp[sum]++;
                }
            }
        }
        return cnt;
    }
};