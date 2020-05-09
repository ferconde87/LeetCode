/*
Runtime: 372 ms, faster than 51.90% of C++ online submissions for Maximum Frequency Stack.
Memory Usage: 87 MB, less than 8.33% of C++ online submissions for Maximum Frequency Stack.
*/

//Simple code with no-iterator usage and without deleting from the unordered_maps when the freq goes to 0 or the stack is empty
class FreqStack {
private:
    unordered_map<int, stack<int> > amount_elements;
    unordered_map<int, int> freq;
    int max_freq;
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        int f = freq[x]++;
        max_freq = max(max_freq, f);
        amount_elements[f].push(x);
    }
    
    int pop() {
        int x = amount_elements[max_freq].top();
        amount_elements[max_freq].pop();
        if(amount_elements[max_freq].empty()) max_freq--;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
