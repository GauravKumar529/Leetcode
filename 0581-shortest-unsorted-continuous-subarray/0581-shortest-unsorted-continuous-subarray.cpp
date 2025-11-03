class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -1;
        
        // Find first out-of-order from left
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                start = i;
                break;
            }
        }

        if (start == -1) return 0; // already sorted

        // Find first out-of-order from right
        for (int j = n - 1; j > 0; j--) {
            if (nums[j] < nums[j - 1]) {
                end = j;
                break;
            }
        }

        // Now expand boundaries if there are smaller/larger elements inside the unsorted region
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = start; i <= end; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        while (start > 0 && nums[start - 1] > mn) start--;
        while (end < n - 1 && nums[end + 1] < mx) end++;

        return end - start + 1;
    }
};
