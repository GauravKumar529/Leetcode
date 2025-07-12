class Solution {
public:
long long  func(vector<int> & v, long long mid, long long m, long long k) {
    int cnt = 0;
    int nOfB = 0;
    for(int i = 0;i< v.size() ;i++){
        if(mid >= v[i])  cnt++;
        else {
            nOfB += (cnt/ k );
            cnt = 0 ;
        }
    }
    nOfB += cnt / k;
    return nOfB >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long low = *min_element(bloomDay.begin() , bloomDay.end());
        long long high = *max_element(bloomDay.begin() , bloomDay.end());
        long long val = k *1LL * m*1LL;
        if(val> n) return -1;
        while(low <= high)  {
            int    mid = (low +  high) / 2;
            int   res = func(bloomDay , mid , m , k);
            if(res) {
                high = mid - 1;
            
            }
            else low = mid+1;  

        }
        return low;

        
    }
};// curated binary search 
// catch -> you have to careful about overflow case and edge case if(m*k>  n) return -1;
