class Solution {
public:
    int func(vector<int>& arr, int n, int divisor) {
        int sumD = 0;
        for (int i = 0; i < n; i++) {
            sumD += (arr[i] + divisor - 1) / divisor;
        }
        return sumD;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());// instead of using low = 0; and high = n -1;
        // i am using mini val -> 1 TO MAX VALUE FROM THE ARRRAY nums 
        int ans = -1;// predefined the container as well for returning the empty and single element hidden cases 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = func(nums, n, mid);
            if (sum <= threshold) {
                ans = mid;// using a another container to storw the value 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;//  u can also do this with retiurning the low value this will came in ur mind with experience so dont panic 
    }
};
