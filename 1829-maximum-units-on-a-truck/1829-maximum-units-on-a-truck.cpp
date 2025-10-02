class Solution {
public: 
static bool comp(vector<int > v1 , vector<int> v2){
    if(v1[1] > v2[1]) return true ; 
    else return false ; 
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int cnt = 0  , diff = 0 , ans =0 ;
        int cnt1  = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for(int i = 0 ;i<n;i++) {
            cnt +=boxTypes[i][0];
            if(cnt  <= truckSize ){
                cnt1++;
                ans += boxTypes[i][1]* boxTypes[i][0] ;
                diff = truckSize - cnt  ;
            }
            else {
                if(cnt1 == 0 && diff ==0) diff = truckSize ;    
                ans +=diff*  boxTypes[i][1];
                break; 

            }
        }
        return ans ;

    }
};