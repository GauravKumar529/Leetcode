int cnt  = 0;
class Solution {
public:
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int cnt = 0;
    int j = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    return cnt;
}

void  merge(vector<int> & arr , int low , int mid ,int high ) {
    int i = low ;
    int j = mid+1;
    vector<int> temp; 
    while ( i<= mid && j<= high) {
        if( arr[i]<= arr[j] ) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while( i<= mid) temp.push_back(arr[i++]);
    while(j <= high) temp.push_back(arr[j++]);
    for(int i = low ;i<=high;i++){
        arr[i] = temp[i - low];
    }
    return  ; 
     
}
int mergeSort(vector<int>&arr , int low , int high){
    int cnt= 0;
    if(low >= high) return cnt; 
    int mid = (low + high) / 2;
    cnt +=mergeSort(arr , low , mid);
    cnt += mergeSort(arr, mid + 1 , high);
    cnt +=countPairs(arr , low , mid , high);
    merge(arr , low , mid , high);
    return cnt  ; 

}
    int reversePairs(vector<int>& nums){
        return mergeSort(nums ,  0 , nums.size() - 1) ;
        
    }
};