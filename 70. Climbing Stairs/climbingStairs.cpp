class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int last_step = 2;
        int two_last_steps = 1;
        for(int i = 2; i < n; ++i){
            int current = last_step + two_last_steps;
            two_last_steps = last_step;
            last_step = current;
        }
        return last_step;
    }
};
