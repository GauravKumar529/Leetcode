class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        map<int , int > mpp;
        for(int i = 0;i<n;i++){
            int more  = target - arr[i];
            if(mpp.find(more ) != mpp.end()){
                return true ;
            }
            mpp[arr[i] ] = i;
            
        }
        return false ;
    }
};