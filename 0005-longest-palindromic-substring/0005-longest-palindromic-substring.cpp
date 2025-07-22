class Solution {
public: 
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 1;
        if(n == 1)  return s;
        auto expandCenter = [&] (int left , int right ) {
            while(left >=0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            
            int len = right - left  -1;
            if(len >  maxLen ){
                start  = left +1;
                maxLen = len;
            }
            
        }; 
        for(int i = 0;i<n;i++){
            expandCenter(i , i); // for odd  imput 
            expandCenter(i , i+1); //  for ecven input there is a odd output as u can see in test cases 

        } 
        return s.substr(start , maxLen);

    }
};