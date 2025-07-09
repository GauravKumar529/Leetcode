
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // Insert into set to sort and remove duplicates
        set<int> st(nums.begin(), nums.end());

        int maxGap = 0;
        for (auto it = st.begin(); next(it) != st.end(); ++it) {
            int gap = *(next(it)) - *it;
            maxGap = max(maxGap, gap);
        }

        return maxGap;
    }
};
