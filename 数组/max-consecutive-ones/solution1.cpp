class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> zs;
        const int n=nums.size();
        zs.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                zs.push_back(i);
        }
        zs.push_back(n);
        const int z=zs.size();
        int maxz=0;
        for(int i=1;i<z;i++){
            maxz=max(maxz,zs[i]-zs[i-1]-1);
        }
        return maxz;
    }
};