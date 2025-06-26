// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> pos, neg; 
        for(int i = 0;i<n;i++){
            if(arr[i ] >= 0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        int p = 0, q = 0 , i =0;
        while(p< pos.size() && q< neg.size()){
            arr[i++] = pos[p++];
            arr[i++] = neg[q++];
        }
        while(p<pos.size()) arr[i++] = pos[p++];
        while(q< neg.size()) arr[i++] = neg[q++];
        
    }
};