class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //  just  imagine the diagram for this algo  . it is like (from 0 to low -1) all 0,s are present in the sorted  way and (from low  to mid-1 ) all 1,s in sorted order and (from mid to high all are in unsorted that is what we have to sort in such a way that it will this particular (mid to high ) will vanished away  and from (high =1) to n-1  all 2 ,s in sorted )  that a problem intution.
        int low  = 0; //keep the low , (mid or high {your choice }  pointer at ) first index 
        int high = n-1;// last index of nums[]
        int mid = 0;
        while(mid<= high){// condition dont mug up just visualize by help of diagram  above  when crosses what and why?
            if(nums[mid] == 0) {
                swap(nums[mid++],  nums[low++]);// we hve 3 cases if nums[mid] == 0,1,2   different  things possible can be visualize using diagram above 
            }
            else if(nums[mid] == 1){
                mid++;// no changes becz its already sorted just move the pointer away

            }
            else swap(nums[mid], nums[high--]);// keep the nums[mid] to the right ward in diagram 

        }
        return ;//done





        
        
    }
};