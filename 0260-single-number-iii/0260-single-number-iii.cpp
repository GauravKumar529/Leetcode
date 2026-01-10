class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long  Xor = 0;
        for(int i = 0; i < n;i++ ) {
            Xor  = Xor ^ nums[i];

        }
        // mask-> right most set bit - find ;
         long long  mask = Xor & (~Xor + 1);
        int g1 = 0, g2 =0;
        for(int i = 0; i < n;i++) {
            if(mask & nums[i]) {
                g1 ^= nums[i];

            }else {
                g2 ^= nums[i];
            }
        }
        return {g1 , g2};

        
    }
};