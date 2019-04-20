class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int cnt=0;
        
        for(int i:nums){
            if(i==maj)
                cnt++;
            else{
                cnt--;
                if(cnt==0){
                    maj=i;
                    cnt=1;
                }
            }
        }
        return maj;
    }
};