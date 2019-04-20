class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zcnt=0;
        const int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                zcnt++;
            else
                nums[i-zcnt]=nums[i];
        }
        for(int i=n-1;i>=n-zcnt;i--)
            nums[i]=0;
    }
};