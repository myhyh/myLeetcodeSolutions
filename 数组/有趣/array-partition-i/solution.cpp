class Solution {
public:
    //�����κ����京���ص��Ľ�,����[1,3],[2,4],������ͨ��������ɲ��ص��õ����ŵĽ�
    //��ȫ���ص��Ľ�ֻ��һ��,����[1,2],[3,4],����...
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