class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m+n-1;i++){
            int x=(m-i-1)>0?(m-i-1):0;
            int y= x!=0?0:(1+i-m);
            int v=matrix[x][y];
            for(;x<m&&y<n;x++,y++){
                if(matrix[x][y]!=v)
                    return false;
            }
        }
        return true;
    }
};