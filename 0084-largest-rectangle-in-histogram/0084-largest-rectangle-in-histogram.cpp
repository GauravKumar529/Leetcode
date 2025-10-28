class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea =0;
         int nse ,pse ;
        stack<int> st;
        for(int i =0 ; i< n;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                nse = i ;
                pse = st.empty() ?-1: st.top();
                maxArea = max(maxArea , (int) (heights[element] * (nse - pse - 1))) ;
            }
            st.push(i) ;
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            nse = n ;
            pse = st.empty()?-1 : st.top();
            maxArea = max(maxArea , (int) (heights[element] * (nse - pse - 1))) ;
        }
        return maxArea ;
    }
};