class Solution {
public:
using vii = vector<vector<int>> ;
using vi  = vector<int>;
void pass( int idx, int n, vi & ds , vii &res ,vi &v) {
    res.push_back(ds);
    for(int i = idx;i< n;i++){
        if(i != idx&& v[i] == v[i - 1]) continue ;
        ds.push_back(v[i]) ;
        pass(i +1 , n , ds, res ,v);
        ds.pop_back();
    }    
    return  ;
} 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vi ds;
        vii res; 
        pass(0 , n ,ds , res ,  nums);
        return res; 
        
    }
};