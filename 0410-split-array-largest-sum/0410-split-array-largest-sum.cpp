class Solution {
public:
int findSubarray(vector<int> &arr, int mid ) {
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return INT_MAX; // if nobody assigns 
            
            sum += arr[i];
            if (sum > mid) {
                cnt++;
                sum = arr[i];
            }
        }
        return cnt;
}

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size( );
        if(n  <  k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;

            if (findSubarray(nums, mid) <= k) {
              //  ans = mid;         // store possible answer
                high = mid- 1;    // try to find a better (smaller) one
            } else {
                low = mid + 1;     // increase page limit
            }
        }
        return low;
    
        
        
    }
};
// its a simple problem of binary similar to book allocation and waht i ll do is , 
// hey , find the ranges and then find which one os eliminate for BS ON Answer  for finding min(max) ;
//tc- > as same as o(log(base2(sum(arr) - max(arr)) ) *  n ) // n for another callled function 