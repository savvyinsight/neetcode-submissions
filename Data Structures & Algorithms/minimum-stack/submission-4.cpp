class MinStack {
public:
    stack<long> st;
    long min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min = val;
        }else{
            st.push(val-min);
            if(val-min<0){
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long pop = st.top();
        st.pop();

        if(pop<0){
            min = min-pop;
        }
    }
    
    int top() {
        if(st.top()<0){
            return min;
        }else{
            return min+st.top();
        }
    }
    
    int getMin() {
        return min;
    }
};
