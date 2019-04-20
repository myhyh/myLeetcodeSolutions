class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int N=A.size();
        auto dp=new int*[N];
        for(int i=0;i<N;i++){
            dp[i]=new int[N];
        }
        for(int i=0;i<N-1;i++)
            memset(dp[i],0x7f,4*N);
        copy(A[N-1].begin(),A[N-1].end(),dp[N-1]);
        for(int i=N-2;i>=0;i--){
            for(int j=0;j<N;j++){
                if(j-1>=0)
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                dp[i][j]=min(dp[i][j],dp[i+1][j]);
                if(j+1<N)
                    dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
                dp[i][j]+=A[i][j];
            }
        }
        return *min_element(&dp[0][0],
                           (&dp[0][0])+N);
    }
};