/*
Runtime: 404 ms, faster than 34.66% of C++ online submissions for Maximum Frequency Stack.
Memory Usage: 96.9 MB, less than 8.33% of C++ online submissions for Maximum Frequency Stack.
*/
class FreqStack {
private:
    unordered_map<int, stack<int> > times_elements;
    unordered_map<int, int> elems;
    int max_freq;
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int elem) {
        elems[elem]++;
        max_freq = max(max_freq, elems[elem]);
        times_elements[elems[elem]].push(elem);
    }
    
    int pop() {
        auto its = times_elements.find(max_freq);
        int elem = its->second.top();
        its->second.pop();
        if(its->second.empty()){
            max_freq--;
            times_elements.erase(its);
        } 
        auto it = elems.find(elem);
        it->second--;
        if(it->second==0) elems.erase(it);
        return elem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */