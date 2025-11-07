class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res ;
        map<int ,int> mpp;
        for(int i = 0; i< k;i++) mpp[nums[i]]++;
        res.push_back(mpp.rbegin()->first);
        for(int i = k ;i < n;i++) {
            mpp[nums[i - k]]--;
            if(mpp[nums[i - k]] ==0) mpp.erase(nums[i - k]);
            mpp[nums[i]]++;
            res.push_back(mpp.rbegin()->first);
        }
        return res ;
        
    }
};