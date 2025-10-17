class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();
        if(n ==0 ) return 0;
        vector<int> preMax(n);
        vector<int> suffixMax(n);
        preMax[0] = height[0];
        suffixMax[n-1] = height[n- 1];
        //prefixMax  precmpute ;
        for(int i = 1 ; i <  n;i++){
            preMax[i] = max(height[i] , preMax[i- 1]);
        }

        //suffixMax  precmpute ;
        for(int i = n-2 ; i>=0;i--){
            suffixMax[i] = max(height[i] , suffixMax[i+1]);
        }


        int total = 0;
        long long trap = 0;
        for(int i = 0 ;i< n;i++){
            total = min(preMax[i] , suffixMax[i] ) - height[i];
            if(total >0) trap += total ;

            
        }
        return trap ;

    }
};