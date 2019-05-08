class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n=nums.size();
        int total=(n*(n+1))/2;
        for(int i:nums)
            total-=i;
        return total;
    }
};