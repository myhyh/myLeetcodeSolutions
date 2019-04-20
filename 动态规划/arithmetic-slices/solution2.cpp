class Solution {
public:
//解决了重复计算相同的序列的问题
    int numberOfArithmeticSlices(vector<int>& A) {
        const int n=A.size();
        auto dp=vector<int>(n);
        int sum=0;
        for(int i=2;i<n;i++){
            if(A[i-1]-A[i-2]==A[i]-A[i-1]){
                dp[i]=1+dp[i-1];
                sum+=dp[i];
            }
        }
        return sum;
    }
};