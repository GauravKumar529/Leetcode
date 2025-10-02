class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        bool ch = true ;
        int cnt5  = 0 , cnt10 = 0 , cnt20 = 0;
        for(int i =  0 ; i< n;i++){
            if(bills[i] ==5) cnt5++;
            else {
                if(bills[i] == 10) cnt10++;


                int num = bills[i]  - 5 ;
                if(num == 5) {
                    if(cnt5<1) {
                        return false;
                    }
                    else cnt5--;
                }
                else{
                    if(cnt10>0 && cnt5 >0 ) {
                        cnt5--;
                        cnt10--;
                    }
                    else if(cnt5 >=3){
                        cnt5 -= 3 ;
                    }
                    else return false ; 
                }
            }   
        }
        return true ;  ;

        
    }
};
// greesyin this -> distribute rupees in such a way that every customer get their change as most as possible tbhi ans  = true aayega 

// if every need this -> check uf ans exist or not -> that a think of greedily 
// how greedy is works -> 