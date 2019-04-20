class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //动态规划,比贪心慢一些
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });
        const int n=pairs.size();
        vector<int> dp=vector<int>(n,1);
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        return dp[n-1];
    }
};