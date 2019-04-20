class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        const int m=nums.size(),n=nums[0].size();
        if(m*n!=r*c)
            return nums;
        vector<vector<int>> result(r,vector<int>(c));
        int nr=0,nc=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                result[nr][nc]=nums[i][j];
                nc++;
                if(nc==c){
                    nc=0;
                    nr++;
                }
            }
        return result;
    }
};