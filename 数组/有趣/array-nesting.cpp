class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        const int n=nums.size();
        vector<int> idxes(n);
        int cmax=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=-1){
                int count=0;
                int start=i;
                while(nums[start]!=-1){
                    int tmp=nums[start];
                    nums[start]=-1;
                    start=tmp;
                    count++;
                }
                cmax=max(count,cmax);
            }
        }
        return cmax;
    }
};