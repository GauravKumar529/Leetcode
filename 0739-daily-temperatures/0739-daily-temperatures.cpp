class Solution {
public:
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
// / nge index array starts here 

vector<int> findnge(vi &arr,int n) {
    stack<int> st ;
    vi nge(n);
    for(int i = n - 1 ; i>=0;i--){
    while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        nge[i] = st.empty()?-1 : st.top();
        st.push(i);
    }
    return nge ;
}
//nge ends here
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //why not 2 pointer->> we move j tilll continon fails , and then reset the j back -> no two pointer
        // then i think ->> store the elmenet somewhere ->>\
        //  then think  what i need next greater element index then currrent ->> nge(stack)
        int n = temperatures.size();
        
        vi res(n);
        vi NGE = findnge(temperatures , n);
        for(int i = 0;i <n ;i++) {
            if(NGE[i] == -1) res[i] = 0;
            else res[i] = NGE[i] - i;
        }
        return res; 
    }
};