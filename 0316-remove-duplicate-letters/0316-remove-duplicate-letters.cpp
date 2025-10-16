class Solution {
public:
    string removeDuplicateLetters(string s) {
        //string implementation 
        int n = s.size();
        string res = "";
        vector<int> LI(26);
        vector<bool > taken(26 , false );
        for(int i = 0  ; i < n;i++)
        {
            char ch  = s[i];
            int idx = ch- 'a';
            LI[idx] = i;
        }
        for(int i = 0 ; i< n;i++){
            char ch = s[i];
            int idx = ch - 'a';
            if(taken[idx]) continue ;
            else {
                while(res.size() >0 && res.back() > s[i] && LI[res.back() - 'a'] > i){
                    taken[res.back() - 'a'] = false ;
                    res.pop_back();

                } 
                res.push_back(s[i]);
                taken[idx] = true ;
            }
        }
        return res ;


        
    }
};