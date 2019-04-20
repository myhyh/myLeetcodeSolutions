class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        const int n=nums.size();
        unordered_set<int> ress;
        for(int i:nums)
            ress.insert(i);
        for(int i=1;i<=n;i++)
            if(ress.find(i)==ress.end())
                result.push_back(i);
        return result;
    }
};