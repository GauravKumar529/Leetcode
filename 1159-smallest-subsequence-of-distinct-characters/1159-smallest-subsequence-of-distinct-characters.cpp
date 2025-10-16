class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string res = "";
        vector<int> lastidx(26);
        vector<bool> taken(26 , false );
        for(int  i = 0 ; i< n;i++){
            char ch = s[i];
            int idx = ch - 'a';
            lastidx[idx] = i;

        }
        for(int  i = 0 ;  i< n;i++){
            char ch = s[i];

            if(taken[ch - 'a'] ) continue ;
            while(res.size() > 0 && res.back() > s[i] && lastidx[res.back() - 'a'] > i) {
                taken[res.back() - 'a'] = false ;
                res.pop_back();

            }
            res.push_back(s[i]);
            taken[res.back() - 'a'] = true  ;
        }
        return res ;
    }
};