class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        multiset<int> ms;
        for(int i = 0;i<n;i++){
            ms.insert(arr[i]);
        }
        int i = 0;
        for(auto it:ms){
            arr[i++] = it;
        }
        return ;
    }
};