class Solution {
public:
using ll = long long ;
const int MOD = 1e9 + 7;
vector<int> findnse(vector<int>& arr){
    int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop until we find a smaller element
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

            // If no smaller element on right → use n
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
}
vector<int> findpsse(vector<int>& arr){
    int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Pop until we find a smaller or equal element
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            // If none on left → use -1
            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return psee;

}

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int > psse  = findpsse(arr);
        ll total = 0;
        int n = arr.size();
        for(int  i = 0 ; i  < n;i++){
            ll left = (i-psse[i]);
            ll right  = (nse[i] - i);
            total = 1LL*((total + (right * left) %MOD * arr[i]) %MOD); 
        }
        return (int) total; 
    }
};