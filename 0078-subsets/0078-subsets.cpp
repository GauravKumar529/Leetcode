class Solution {
public:
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define all(x) (x).begin(), (x).end()
#define pb push_back
void fun(int i  , vii & res ,vi &ds , vi & nums ,int n ){
    if(i == n) {
        res.pb(ds) ;
        return  ;
    }
    ds.pb(nums[i]);
    fun(i+1 , res , ds,  nums, n) ;
    ds.pop_back();
    fun(i+1 , res , ds,  nums, n) ;
    return  ; 
    
    
}


    vector<vector<int>> subsets(vector<int>& nums) {
        vii res ; 
        int n = nums.size();
        vi ds ; 
        fun(0 , res , ds ,  nums , n );
        return res;


        
    }
};