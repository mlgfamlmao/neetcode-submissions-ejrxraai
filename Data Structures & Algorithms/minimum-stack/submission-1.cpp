#include <stack>

class MinStack {
    
    std::stack<int> st;
    std::stack<int> MinSt;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (MinSt.empty()){
            MinSt.push(val);
        }
        else{

        MinSt.push(std::min(MinSt.top(), val));}
    }
    
    void pop() {
        MinSt.pop();
 
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return MinSt.top();
    }
};