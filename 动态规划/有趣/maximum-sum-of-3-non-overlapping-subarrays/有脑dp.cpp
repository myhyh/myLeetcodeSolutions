class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //将数组分为三段，算出前段最大的下标，后段最大的下标，然后对于中间一段取的所有情况迭代处理

        const int n=nums.size();
        int* ks=new int[n-k+1]();
        for(int i=0;i<k;i++){
            ks[0]+=nums[i];
        }
        for(int i=k;i<n;i++){
            ks[i-k+1]=ks[i-k]-nums[i-k]+nums[i];
        }
        
        //算出前段最大的下标
        int* maxstart=new int[n-k+1]();
        int vidx=0;
        for(int i=0;i<n-k+1;i++){
            if(ks[i]>ks[vidx]){
                vidx=i;
            }
            maxstart[i]=vidx;
        }

        //算出后段最大的下标
        int* maxend=new int[n-k+1]();
        vidx=n-k;
        for(int i=n;i>=k;i--){
            if(ks[i-k]>ks[vidx]){
                vidx=i-k;
            }
            maxend[i-k]=vidx;
        }
        int maxval=0;
        vector<int> res(3);

        //对于中间一段取的所有情况迭代处理
        for(int j=k;j<n-2*k+1;j++){
            if(maxval<ks[maxstart[j-k]]+ks[j]+ks[maxend[j+k]]){
                maxval=ks[maxstart[j-k]]+ks[j]+ks[maxend[j+k]];
                res[0]=maxstart[j-k];
                res[1]=j;
                res[2]=maxend[j+k];
            }
        }
        return res;
    }
};