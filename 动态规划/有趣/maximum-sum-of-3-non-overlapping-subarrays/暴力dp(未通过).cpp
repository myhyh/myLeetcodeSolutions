class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n=nums.size();
        int* ks=new int[n-k+1]();
        for(int i=0;i<k;i++){
            ks[0]+=nums[i];
        }
        for(int i=k;i<n;i++){
            ks[i-k+1]=ks[i-k]-nums[i-k]+nums[i];
        }
        int maxres=0;
        int resi,resj,resl;
        for(int i=0;i<=n-3*k;i++){
            for(int j=i+k;j<=n-2*k;j++){
                for(int l=j+k;l<=n-k;l++){
                    int res=ks[i]+ks[j]+ks[l];
                    if(res>maxres){
                        maxres=res;
                        resi=i;resj=j;resl=l;
                    }
                }
            }
        }
        vector<int> residx(3);
        residx[0]=resi;
        residx[1]=resj;
        residx[2]=resl;
        return residx;
    }
};