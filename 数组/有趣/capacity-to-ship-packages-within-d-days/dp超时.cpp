class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        const int n=weights.size();
        vector<vector<int>> dp(n,vector<int>(D,-1));
        return swd(weights,0,D,dp);
    }
    int swd(vector<int>& weights,int s,int D,vector<vector<int>> &dp){
        const int n=weights.size();
        if(dp[s][D-1]!=-1)
            return dp[s][D-1];
        if(D==1){
            int total=0;
            for(int i=s;i<n;i++){
                total+=weights[i];
            }
            return total;
        }
        int maxw=0x7fffffff;
        int total=weights[s];
        for(int i=s+1;i<=n-D+1;i++){
            maxw=min(maxw,max(total,swd(weights,i,D-1,dp)));
            total+=weights[i];
        }
        dp[s][D-1]=maxw;
        return maxw;
    }
};