class MinStack {
public:
    stack<int> st,minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty() || minstack.top()>=val){
            minstack.push(val);
        }
    }
    
    void pop() {
        if(!st.empty() && minstack.top() == st.top()){
            minstack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
