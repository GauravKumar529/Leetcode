class Solution {
public:
void pass(int i , vector<int>&ds , vector<int>&arr, vector<vector<int>>& res , int target , int n ){
    if(target <0) return ; // prevent invalid paths
    if(i ==n) {
        if(target ==0) res.push_back(ds) ;
        return  ;
    }
    ds.push_back(arr[i]) ; // when pick the element 
    pass(i , ds, arr ,res ,target - arr[i] , n);
    ds.pop_back(); // when returning please pop backit from ds 
    pass(i+1, ds,arr, res , target , n); // rest not pick case move 
    return ;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res ; 
        vector<int> ds; 
        pass( 0 , ds,candidates ,res, target , n);
        return res ; 

        
    }
};