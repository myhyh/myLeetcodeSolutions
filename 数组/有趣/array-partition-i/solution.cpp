class Solution {
public:
    //对于任何区间含有重叠的解,比如[1,3],[2,4],都可以通过交换变成不重叠得到更优的解
    //完全不重叠的解只有一个,就是[1,2],[3,4],所以...
    int arrayPairSum(vector<int>& nums) {
        const int n=nums.size()/2;
        sort(nums.begin(),nums.end());
        int result=0;
        for(int i=0;i<2*n;i+=2){
            result+=nums[i];
        }
        return result;
    }
};