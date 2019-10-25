class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 2) return 0;
        int one_step_back = cost[1];
        int two_steps_back = cost[0];
        for(int i = 2; i < n; ++i){
            //current := cheapest cost using i-th-step
            int current = cost[i] + min(one_step_back, two_steps_back);
            two_steps_back = one_step_back;
            one_step_back = current;
        }
        return min(one_step_back, two_steps_back);
    }
};
