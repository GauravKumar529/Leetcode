class Solution {
public:
    void dfs(vector<bool> & vis,int n,vector<vector<int>>&nums ,int curr ) {


        for(int i  = 0; i < n;i++) {
            if(nums[curr][i] == 1  && !vis[i] ){
                vis[i] = 1;
                dfs(vis , n , nums , i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt  = 0;
        int n = isConnected.size();

        vector<bool> vis(n , 0);
        for(int i = 0; i < n;i++ ) {
            if(!vis[i] ) {
                cnt++;
                dfs(vis ,  n, isConnected, i );

            }
        }
        return  cnt ;


        
    }
};