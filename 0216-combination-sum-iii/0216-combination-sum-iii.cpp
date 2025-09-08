class Solution {
public:
#define vi vector<int> 
#define vii vector<vector<int>> 
#define pb push_back
void pass(vi &ds , vii&res, int idx, int n, int target){
    if(target  <0) return ;
    if(target ==0) {
        if(ds.size() == n) res.pb(ds);
        return   ;
    }
    for(int i = idx;i<=9;i++) {
        if(i<= target) {

            ds.pb(i) ;
            pass(ds,res, i+1, n , target - i);
            ds.pop_back();
        }
        else  return  ;  
    }
    return ;

}
     vector<vector<int>> combinationSum3(int k, int n) {
        vi ds ;
        vii res ; 
        pass(ds, res , 1 , k , n  );
        return res  ;
        
    }
};