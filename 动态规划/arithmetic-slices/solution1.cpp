class Solution {
public:
    //和palindromic-substrings一模一样的思路，比较慢
    int numberOfArithmeticSlices(vector<int>& A) {
        const int n=A.size();
        auto dp=vector<vector<bool>>(n,vector<bool>(n,false));
        for(int i=0;i<n-2;i++){
            for(int j=i;j<i+2;j++){
                dp[i][j]=true;
            }
        }
        int res=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+2;j<n;j++){
                dp[i][j]=A[j]-A[j-1]==A[i+1]-A[i] && dp[i][j-1];
                if(dp[i][j])
                    res++;
            }
        }
        return res;
    }
};