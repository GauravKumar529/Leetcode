class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res ;
        sort(nums.begin() , nums.end());

        int n = nums.size();
        int i = 1;
        while(i< n ){
            if(nums[i] != nums[i -1] ){
                res.push_back(nums[i - 1]);
                i++;
            }
            else i+= 2;

        }
        if(res.size() == 1) res.push_back(nums[n - 1]);
        return res ;
        
    }
};