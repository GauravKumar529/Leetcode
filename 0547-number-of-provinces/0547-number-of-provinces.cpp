class Solution {
public:
void bfs (int curr, int n  ,vector<bool> &vis , vector<vector<int >>  &nums ) {
    queue<int > q ;
    q.push(curr) ;
    vis[curr] = 1;
    while(!q.empty()) {
        int node = q.front() ;
        q.pop();

        for(int i = 0; i < n;i++) {
            if(nums[node][i] == 1 && !vis[i]) {
                vis[i] = 1l;
                q.push(i);

            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();
        int cnt = 0;
        // q.push(0);
        vector<bool> vis(n , 0);
        for(int i = 0; i < n;i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i , n , vis , isConnected );

            }
        }
        return cnt ;

        
    }
};