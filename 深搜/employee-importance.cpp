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
    unordered_map<int,Employee*> db;
    bool inited=false;
    int getImportance(vector<Employee*> employees, int id) {
        if(!inited){
            init(employees);
            inited=true;
        }
        auto e=db[id];
        int im=0;
        for(auto sub:e->subordinates){
            im+=getImportance(employees,sub);
        }
        im+=e->importance;
        return im;
    }
    void init(vector<Employee*> &employees){
        for(auto e:employees){
            db.insert({e->id,e});
        }
    }
};