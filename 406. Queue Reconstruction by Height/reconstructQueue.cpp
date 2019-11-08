/*
Runtime: 440 ms, faster than 5.03% of C++ online submissions for Queue Reconstruction by Height.
Memory Usage: 13.7 MB, less than 19.05% of C++ online submissions for Queue Reconstruction by Height.
*/
class Solution {
public:
    struct node{
        vector<int> hk;
        int geq = 0;
    };
    
    void print(vector<node> & ppl){
        for(auto p : ppl){
            cout << p.hk[0] << " " << p.hk[1] << " " << p.geq << endl;
        }
        cout << endl;
    }
    void print(bool ok, node & p){
        cout << ok << " " << p.hk[0] << "|" << p.hk[1] << "|" << p.geq << endl;
    }
    
    bool rightPosition(node & p){
        return p.hk[1] == p.geq;
    }
    
    void swapPpl(vector<node> & ppl, int i, int j){
        node & a = ppl[i];
        node & b = ppl[j];
        if(a.hk[0] > b.hk[0]){
            b.geq--;
        }else if(a.hk[0] < b.hk[0]){
            a.geq++;
        }else{
            b.geq--;
            a.geq++;
        }
        swap(ppl[i],ppl[j]);
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<node> ppl(n);
        int last_h = INT_MIN;
        int amount = 1;//amount of people with high equal to last_h
        for(int i = 0; i < n; ++i){
            node p;
            p.hk = people[i];
            if(last_h == p.hk[0]){
                p.geq = amount;
                amount++;
            }else{
                last_h = p.hk[0];
                amount = 1;
            }
            ppl[i] = p;
        }
        int i = 0;
        bool change = true;
        while(change){
            i = 0;
            change = false;
            while(i < n-1){
                bool ok = rightPosition(ppl[i]);
                if(!rightPosition(ppl[i])){
                    swapPpl(ppl, i, i+1);
                    change = true;
                }
                i++;
            }
        }
        for(int i = 0; i < n; ++i){
            people[i] = ppl[i].hk;
        }
        return people;
    }
};
