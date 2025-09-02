class Solution {
public:
long double pass(double x , long long n) {
    if(n == 0) return 1.0;
    long double ans  = (double) pass(x , n  /2);
    if(n %2 == 1)  return  (double) x * ans * ans ; 
    else  return (double)ans  * ans  ; 
}
    double myPow(double x, int n) {
        long double num = n;
        if(num < 0) {
            x  = 1 /x ;
            num  *= -1;
        }
        return  (double)pass(x , num);    
    }
};