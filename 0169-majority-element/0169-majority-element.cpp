class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;//moore,s voting algo (whenever we gonna find the majority element  > n/k , k -> const, and i hve to tell answer without using extra space here  , i do this )
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(cnt == 0) { 
                cnt++;
                ele = nums[i];
            }
            else if( nums[i] == ele) cnt++;
            else cnt--;
        }
        int cnt1 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == ele) cnt1++;
        }
        if(cnt1> n/2) return ele;
        return -1;

    }
};