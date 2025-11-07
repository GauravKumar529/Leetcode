class Solution {
public:
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
static bool cmp(pii a , pii b){
    if(a.second != b.second) return a.second> b.second;
    else return a.first>  b.first   ;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vi res ;
        int  first = 0 ;
        int n = nums.size();
        int last = k - 1;
        while(last< n){
            
            vector<pii> v;
            // for storing in vector<pair<int , int>> 
            for(int i = first; i<= last ;i++ ){
                bool found = false;
                // check if already exists in v
                for (auto &p : v) {
                    if (p.first == nums[i]) {
                        p.second++;     // increase freq
                        found = true;
                        break;
                    }
                }
            

                // if not found, push new pair
                if (!found) {
                    v.push_back({nums[i], 1});
                }
            }
            sort(v.begin() , v.end() , cmp);
            // end of vpii
            ll sum = 0;
            for(int i = 0; i< min((int)v.size() , x );i++){
                sum +=  1LL*(v[i].first *  v[i].second);
            }
            res .pb(sum);
            first++;
            last++;
        }
        return res ;
        
    }
};