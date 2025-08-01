
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long left = 0, total = 0;
        int maxFreq = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];
            // i.e., cost = nums[right] * windowSize - total
            while ((long long)nums[right] * (right - left + 1) - total > k) { // dont forget to make typecast it 
                total -= nums[left];
                left++;
            }

            //Update maxFreq
            maxFreq = max(maxFreq, (int)(right - left + 1));
        }

        return maxFreq;
    }
};
