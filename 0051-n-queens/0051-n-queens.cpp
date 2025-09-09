class Solution {
public:
// bool BlackBOx(int row , int col ,   vector<string >& ds , int n ) {
//     //upperdiagonal
//      int i = row, j = col;
//     while(i>=0 && j >=0 ) {
//         if(ds[i][j] == 'Q' ) return  false ;
//         i--;
//         j--;
//     }
//     i = row, j = col;
//     //leftDiagonal
//     while(j>=0) {
//         if(ds[i][j] == 'Q') return false ;
//         j--;
//     }
//     i = row, j = col;
//     // lowerDiagonal
//     while(i<n && j >=0) {
//         if(ds[i][j] == 'Q') return false ; 
//         i++;
//         j--;

//     }
//     return true ;
// }
void  solve(int col, int n,  vector<string >& ds,vector<vector<string>> &res, vector<int>&lr , vector<int>&ud, vector<int>&ld) {
    if(col == n){ 
        res.push_back(ds);
        return ; 

    }
    for(int i = 0;i< n;i++) {
        // if(BlackBOx(i , col, ds,n)) { // its a blackboX technique
        //     ds[i][col] = 'Q';
        //     solve(col +1 , n , ds, res );;
        //     ds[i][col] = '.';
        // }
        if(ld[i +col] == 0 && ud[n - 1 + col - i] == 0 && lr[i] == 0) {
            ds[i][col] = 'Q';
            lr[i]= 1;
            ud[n - 1 + col- i] = 1;
            ld[i + col] = 1;
            solve(col + 1, n , ds ,res , lr, ud, ld);
            ds[i][col] = '.';
            lr[i]= 0;
            ud[n - 1 + col - i]  = 0;
            ld[i + col] = 0;
        }  

    }
    return  ;
}
    vector<vector<string>> solveNQueens(int n){  
        vector<vector<string>> res ;
        vector<string> ds(n, string(n, '.'));
        vector<int>leftRow(n, 0), upperDiag (2*n - 1, 0) , lowerDiag(2*n - 1, 0) ;

        solve(0 , n , ds,res, leftRow, upperDiag , lowerDiag);
        return  res  ;       
    }
};