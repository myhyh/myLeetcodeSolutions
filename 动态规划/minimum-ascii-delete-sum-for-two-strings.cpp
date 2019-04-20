class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int n1=s1.size(),n2=s2.size();
        vector<vector<int>> dp=vector<vector<int>>(n1+1,vector<int>(n2+1,0));
        dp[n1][n2]=0;
        for(int i=n2-1;i>=0;i--){
            dp[n1][i]=dp[n1][i+1]+s2[i];
        }
        for(int i=n1-1;i>=0;i--){
            dp[i][n2]=dp[i+1][n2]+s1[i];
        }
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                dp[i][j]=s1[i]==s2[j]?dp[i+1][j+1]:
                min(s1[i]+dp[i+1][j],s2[j]+dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};