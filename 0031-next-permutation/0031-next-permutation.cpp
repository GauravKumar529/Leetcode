class Solution {
public:
    void nextPermutation(vector<int>& nums) { // on algo there are three steps  you know very well 
        int n  = nums.size();
        int idx= -1;
        for(int i = n-2;i>=0;i--){// in first one i,ll ifnd that element index wwhich is  lesser then next one you may take ex [ 2,1,5,4,3,0,0]; iterating from last which is easy //
            if(nums[i] < nums[i+1]){ // 
                idx = i;// store the idx and break it //
                break;
            }
        }
        if(idx == -1) { // if ther is no one element which is leesser then anpther one the n this is the case [like araay arranged in descending order ]  just reverse it //
            reverse(nums.begin() , nums.end());
            return ;// return  is IMPORTANT HERE . THAT A TRICKY THING 
        }
        for(int i = n-1;i>idx;i--){ 
            if(nums[i] > nums[idx]){ //  now , we find element just greater then indx positioned wala , iterating from laster on e element  and if you find it just do below  snippet //[2,3,5,4,1,0,0] /////////AFTER SWAP
                swap(nums[i] ,  nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+ idx+1, nums.end()); // now you,ll be like [2,3,(0 0 1 4 5 ) in ascending ]
        return ;
        
    }
};