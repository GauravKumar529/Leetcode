class Solution {
public:
    int findMin(vector<int>& nums) { //  i,ll be going to mid and firstly gonna to left half and twll hey listen left half are sorted , below 
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high  - low) / 2;
            if(nums[low]<= nums[mid]){//  hey listen for left half , are you soreted , update the ans to my first idx  and omit the left half by change the low pointer to mid+1 , JUST VISUALIZE < DRY RUN AND TRY TO WRITE CODE 
                ans = min(ans , nums[low]);
                low = mid+1;
            }
            else {
                ans = min(ans , nums[mid]);// if not then update ans  and pointer as well 
                high   =  mid -1;
            }
            
        }
        return ans;
        
    }
};