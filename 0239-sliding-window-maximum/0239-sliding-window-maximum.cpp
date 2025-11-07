class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // build intution-< after brute-> ask hm, kr kya rhe hai , kyon kar rhehai , ->>        what           d i need s for this one so that time comp less lge
        // its not problem , its a concept 

/*
 story Points:
    step1:when new element comes  nums[i], make space fot it ,(window size cannt then k)
    step2: now , when nums[i]comes , there is no ned of elements lesser thrn nums[i]
    step3: now push i in deque ->. for num[i];
    step4:(i>= k-1) then deq.front() -> push in res   
*/ 

        int n = nums.size();
        deque<int> dq;
        vector<int> res ;
        for(int i = 0; i < n;i++) {
            // step1
            while(!dq.empty() && dq.front() <= (i-k)){
                dq.pop_front();
            }
            // step2
            while(!dq.empty() &&  nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // step3
            dq.push_back(i);
            // step4
            if(i>= k- 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res ;


    }
};