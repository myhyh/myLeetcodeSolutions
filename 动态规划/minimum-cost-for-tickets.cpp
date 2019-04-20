class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int n=days.size();
        int *dp=new int[n+1];
        memset(dp+1,0x7f,n*4);
        dp[0]=0;
        for(int i=0;i<n;i++){
            dp[i+1]=min(dp[i+1],dp[i]+costs[0]);
            int j=i+1;
            while(j<n && days[j]<days[i]+7)j++;
            dp[j]=min(dp[j],dp[i]+costs[1]);
            while(j<n && days[j]<days[i]+30)j++;
            dp[j]=min(dp[j],dp[i]+costs[2]);
        }
        return dp[n];
    }
};