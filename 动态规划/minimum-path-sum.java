class Solution {
    public int minPathSum(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        
        int[][] lens=new int[m+1][n+1];
        lens[1][0]=0;
        lens[0][1]=0;
        for(int i=2;i<=n;i++){
            lens[0][i]=0x7fffffff;
        }
        for(int i=2;i<=m;i++){
            lens[i][0]=0x7fffffff;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                lens[i][j]=Math.min(lens[i][j-1],lens[i-1][j])+grid[i-1][j-1];
            }
        }
        return lens[m][n];
    }
}