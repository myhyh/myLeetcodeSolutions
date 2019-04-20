class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=0x80000000;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0)
                sum=0;
        }
        return maxsum;
    }
};