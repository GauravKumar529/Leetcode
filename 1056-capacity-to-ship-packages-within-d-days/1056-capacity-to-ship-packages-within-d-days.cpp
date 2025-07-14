class Solution {
public:
int daysCount(vector<int > &arr, int  n, int capacity ){
    int day = 1;
    int load  = 0;
    for(int i = 0;i<n;i++){
        load  += arr[i];
        if(load   > capacity){
            day++;
            load = arr[i ];

        }
    }
    return day ;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ;
        int low = *max_element(weights.begin() ,weights.end() );
        int high = accumulate(weights.begin() ,weights.end()  , 0);
        while(low <= high ) {
            int capacity = (low+  high ) / 2;
             if(  daysCount( weights , n,  capacity ) >  days ) low = capacity + 1;
            else high = capacity - 1;


        }
        return low  ;
         

        
    }
};
// tc -> o(log(sum(arr) - max(arr) ) * n);
// intution - > simply firstly write the brute force and then go to this one , herehow 
// basically , two htings are main
// 1) -> find the ranges in which my ans is lying 
// 2) ->  which will be teminate or oimit from the BS  after oprating mid one 