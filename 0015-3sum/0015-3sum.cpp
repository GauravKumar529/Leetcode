class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int >> res;
        for(int i = 0;i<n;i++) {
            if(i >0 && nums[i] == nums[i- 1]) continue ;
            int j = i + 1;
            int k = n  - 1;
            while( j < k ) {
                int sum = nums[i] + nums[j]  + nums[k];
                if(sum < 0) {
                    j++;

                }
                else if(sum >0) {
                    k--;

                }
                else {
                    res.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    while(  j<k && nums[j] == nums[j - 1])  j++;
                    k--;
                    while( j< k && nums[k] == nums[k+1]) k--;

                }

            }
          
        }
        return res ;
        
    }
};






// here i use the 3 pointers in this how -> take o(n^2 ) for sure and i want to optiised o(n^3) to somewhere like o(n^2* logn ) ab=nd moreever i wnat to optimised the sc of this via not using extra ds to store unique triplets  ///

//  this is best rQ for 2 pointer pattern -> most imp and rev  question before google intervIEW