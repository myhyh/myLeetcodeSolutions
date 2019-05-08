class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n=nums.length;
        int[][] dp=new int[n][n];
        for(int l=1;l<n;l++){
            for(int s=0;l+s<n;s++){
                int e=l+s;
                dp[s][e]=Math.max(nums[s]-dp[s+1][e],nums[e]-dp[s][e-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
}