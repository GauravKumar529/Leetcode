class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        long long maxi = 0;
        int i = 0;
        for(int i = 1; i< colors.size() ;i++){
            if(colors[i ] == colors[i - 1]) {
                maxi += min(neededTime[i] , neededTime[i - 1]);
                neededTime[i] = max(neededTime[i] , neededTime[i - 1])
                ;
            }
        }
        return  maxi ;
        
    }
};