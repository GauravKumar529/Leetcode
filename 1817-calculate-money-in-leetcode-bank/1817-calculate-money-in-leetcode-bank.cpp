class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int firstday = 1;
        while(n >0) {
            for(int i = 0 ; i < min(n , 7) ;i++){
                res += firstday + i ;
            }
            n -= 7 ;
            firstday++;
        }
        return res ;
        
        
    }
};