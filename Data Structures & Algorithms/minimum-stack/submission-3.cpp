class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minst.empty() || val<=minst.top()){
            minst.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(!minst.empty() && st.top() == minst.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }else{
            return st.top();
        }
    }
};
