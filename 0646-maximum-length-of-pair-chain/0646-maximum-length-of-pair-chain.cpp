class Solution {
public:
static bool comp(vector<int> &a,vector<int> &b){
    if(a[1]< b[1]) return true ;
    else return false ; 
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , comp);
        int i = 0 ;
        int cnt =  1;
        int n = pairs.size();


        if(n == 1) return cnt ;
        for(int j = 1;j< n;j++){
            if(pairs[i][1] < pairs[j][0]){
                cnt++;
                i = j ;
            }
        }
       
        return  cnt  ; 
        
    }
};