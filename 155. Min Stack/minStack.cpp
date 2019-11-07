/*
Runtime: 32 ms, faster than 68.18% of C++ online submissions for Min Stack.
Memory Usage: 16.9 MB, less than 89.09% of C++ online submissions for Min Stack.
*/
class MinStack {
private:
    struct node{
        int min_element;
        int value;
    };
    int getMinimum(){
        if (s.empty()) return INT_MAX;
        node top = s.top();
        return top.min_element;
    }
    stack<node> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        int min_element = getMinimum();
        if(x < min_element) min_element = x;
        node newTop;
        newTop.value = x;
        newTop.min_element = min_element;
        s.push(newTop);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().value;
    }
    
    int getMin() {
        return getMinimum();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
