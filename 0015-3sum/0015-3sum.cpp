
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0;
        while(low < n - 2) {
            if(low > 0 && nums[low] == nums[low-1]) { // skip duplicates for low
                low++;
                continue;
            }

            int mid = low + 1;
            int high = n - 1;

            while(mid < high) {
                int sum = nums[low] + nums[mid] + nums[high];
                if(sum < 0) {
                    mid++;
                }
                else if(sum > 0) {
                    high--;
                }
                else {
                    res.push_back({nums[low], nums[mid], nums[high]});
                    mid++;
                    high--; 
                    while(mid < high && nums[mid] == nums[mid-1]) mid++;
                    while(mid < high && nums[high] == nums[high+1]) high--;
                }
            }
            low++;
        }
        return res;     
    }
};
