class MinStack {
public:
    stack<int> st;
    stack<int> minvals;
    MinStack() {
        st ={};
        minvals = {};
    }
    
    void push(int val) {
        st.push(val);
        if(minvals.empty() || val<=minvals.top()){
            minvals.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()==minvals.top()){
            minvals.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minvals.top();
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