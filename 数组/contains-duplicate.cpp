class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nset;
        for(int i:nums){
            if(nset.find(i)!=nset.end())
                return true;
            else
                nset.insert(i);
        }
        return false;
    }
};