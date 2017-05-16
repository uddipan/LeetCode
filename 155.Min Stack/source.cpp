class MinStack {
public:
    stack<int>S, M;
    void push(int x) {
        S.push(x);
        if((M.empty()) || (x <= M.top()))
        {
            M.push(x);
        }
    }
    
    void pop() {
        if(M.top() == S.top())
        {
            M.pop();
        }
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return M.top();
    }
};