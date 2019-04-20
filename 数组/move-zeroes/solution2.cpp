class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        int fast=0;
        const int n= nums.size();
        while(fast<n){
            if(nums[fast]==0)
                fast++;
            else{
                nums[slow]=nums[fast];
                fast++;
                slow++;
            }
        }
        for(int i=slow;i<n;i++)
            nums[i]=0;
    }
};