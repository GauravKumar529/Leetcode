class MinStack {
private: 
stack<long long> st ; 
public:
    MinStack() {
        
    }
    long long mini = 0 ;
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val ;
        }
        else if(val < mini){
            long long val1 = 2LL * val - mini ;
            st.push(val1); 
            mini =  val ;
        }  
        else st.push(val);
    }
    void pop() {
        if(st.top() < mini){
            mini = 2* mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) {
            return  mini;
        }        
        else return st.top();

    }
    
    int getMin() {
        return mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */