class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int n=nums.size();
        int maxz=0;
        int lastz=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int dist=i-lastz-1;
                maxz=max(maxz,dist);
                lastz=i;
            }
        }
        maxz=max(maxz,n-lastz-1);
        return maxz;
    }
};