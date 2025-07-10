class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int  low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low+ (high - low) / 2;
            if(nums[mid] == target ) return true;// if this works return this 
            // now i am checking which of my [part ] is sorted wether right half or left half 
            if(nums[mid] == nums[low] &&  nums[mid ] ==  nums[high]){
                low++;
                high--;
                continue ;
            }
            if(nums[mid] <= nums[high]){ //  firstly i checked for right if the target is present i it lets omit the left wala portion just move the pointer low to mid+1;
                if(nums[mid] <  target && nums[high] >= target ) low =  mid+1;
                else high  =  mid - 1;

            }
            // if  right not sorted then move to left ie else statement 
            else {
                if(nums[low] <=target &&  target <  nums[mid]) high = mid - 1;  //  else elemenrt is present in the left part ,  basically it lies bw left half then move the pointer to .... 
                else low  = mid+1;
            }
        }
        return false ;
        
    }
};