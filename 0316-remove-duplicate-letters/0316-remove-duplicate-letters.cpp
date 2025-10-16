class Solution {
public:
    string removeDuplicateLetters(string s) {
        //taking two array biucket sort for, one for duplicacy , another for-> lexographically placing 
        int n = s.size();
        stack<char> st ;
        vector<bool> taken(26 , false );
        vector<int> lastIdx(26); //aplphabet ke liye 
        for(int i = 0 ; i< n;i++){
            lastIdx[s[i] -'a'] = i;
        }
        for(int i = 0 ; i< n;i++){
            char ch = s[i];
            if(taken[ch - 'a']) continue;
            while(!st.empty() && st.top() > ch &&lastIdx[st.top() - 'a'] > i){
                taken[st.top() - 'a'] = false ;
                st.pop();
            }
            st.push(s[i]) ;
            taken[ch  - 'a']  = true ;
        }
        string res  = "";
        while(!st.empty()) {
            res += st.top();

            st.pop();
        }
        reverse(res.begin() , res.end());
        return res;

    }
};