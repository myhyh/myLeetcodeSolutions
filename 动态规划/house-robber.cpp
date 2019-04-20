class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxin(n);
        vector<int> maxout(n);
        if(n==0)
            return 0;
        if(n<2)
            return nums[0];
        maxin[0]=nums[0];
        maxin[1]=nums[1];
        maxout[0]=0;
        maxout[1]=nums[0];
        for(int i=2;i<n;i++){
            maxin[i]=maxout[i-1]+nums[i];
            maxout[i]=max(maxin[i-1],maxout[i-1]);
        }
        return max(maxin[n-1],maxout[n-1]);
    }
};