/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    unordered_set<int> checked;
    int result = 0;
    unordered_map<int, Employee*> employee_importance;
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.size() == 0) return 0;
        
        for(Employee* e : employees){
            employee_importance[e->id] = e;
        }
        
        auto it = employee_importance.find(id);
        if(it == employee_importance.end()) return 0;
        
        queue<int> ids;
        ids.push(id);
        int result = 0;
        while(!ids.empty()){
            int i = ids.front();
            ids.pop();
            auto e = employee_importance[i];
            result += e->importance;
            vector<int> subordinates = e->subordinates;
            for(int s : subordinates){
                if(checked.find(s)!=checked.end()) continue;
                checked.insert(s);
                ids.push(s);
            }
        }
        return result;
    }
};
