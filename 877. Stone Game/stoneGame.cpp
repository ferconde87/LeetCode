/*
class Solution {
public:
    //In case Alex can only see one rock at a time & no two rocks had the same value
    bool stoneGame(vector<int>& piles) {
        bool playsAlex = true;
        int alex = 0;
        int lee = 0;
        int i = 0;
        int j = piles.size() - 1;
        int optimal = 0;
        while(i <= j){
            if (piles[i] > piles[j]) optimal = piles[i++];
            else optimal = piles[j--];
            if (playsAlex) alex += optimal;
            else lee += optimal;
            optimal = 0;
            playsAlex = !playsAlex;
        }
        return alex > lee;
    }
};
    tests
    [5,2,3,1,1,5]
    [5,2,1,3,1,5]
    [5,1,100,1,1,5]
    [5,1,1,100,1,5]
    [1,2,100,98]
    [1,100,2,98]
    [1,2,1,1]
    [1,1,2,1]
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
