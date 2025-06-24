class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n  = nums.size();
        int i = 0;
        int j = n-1;
        vector< pair<int, int>>p ;
        for(int i = 0;i<n;i++){
            p.push_back({nums[i] , i});
        }
        sort(p.begin(), p.end());
        while(i<j){
            int sum = p[i].first + p[j].first;
            if(sum < target ) i++;
            else if ( sum> target ) j--;
            else return  {p[i].second , p[j].second};
        }
        return {-1, -1};
    }
};