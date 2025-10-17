#include <bits/stdc++.h>   // includes everything (works in most compilers)
using namespace std;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int >premax(n);
        vector<int >suffmax(n);
        premax[0] = nums[0];
        suffmax[n-1] = nums[n-1] ;
        for(int i =1 ; i< n;i++){
            premax[i] = max(nums[i] , premax[i-1]);
        }
        //suffmaxi
        for(int i = n -2 ;i>=0;i--){
            suffmax[i] = max(nums[i] , suffmax[i +1]) ;
        }
        long long res = 0;
        for(int i = 1 ; i< n-1;i++){
            long long  val = (long long)(premax[i - 1] - nums[i]) * suffmax[i + 1];

            res = max(  val ,res );

        }
        return res  ;

    }
};