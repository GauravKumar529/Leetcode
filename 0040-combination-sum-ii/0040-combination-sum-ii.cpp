class Solution {
public:
    void pass(int start, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &res, int n) {
        if(target == 0) {
            res.push_back(ds);
            return;
        }
        for(int i = start; i < n; i++) {
            // skip duplicates at the same recursion depth
            if(i > start && arr[i] == arr[i-1]) continue;

            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            pass(i+1, target - arr[i], arr, ds, res, n); 
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> res;
        vector<int> ds;
        pass(0, target, candidates, ds, res, candidates.size());
        return res;
    }
};
