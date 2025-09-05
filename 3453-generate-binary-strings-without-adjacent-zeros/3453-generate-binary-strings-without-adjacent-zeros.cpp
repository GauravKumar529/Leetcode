class Solution {
public:
vector<string > res;
void fun( int n ,  string s , char lastDigit){
    if(n == s.size() ) {
        res.push_back(s) ;
        return  ;
    }


    fun(n , s +"1" , '1');  
    if(lastDigit != '0') fun(n , s+ "0", '0');
    return;
}
    vector<string> validStrings(int n) {
        fun(n , "", '1');
        return  res  ; 
        
    }
};