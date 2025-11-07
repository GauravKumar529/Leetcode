class StockSpanner {
public:
vector<int> res;
int idx= -1;
stack<pair<int, int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        idx++;
        int ans = 0;
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        ans = idx - (st.empty()?-1: st.top().second);
        st.push({price, idx});   
        return ans ; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */