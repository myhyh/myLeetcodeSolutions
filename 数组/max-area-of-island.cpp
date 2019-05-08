class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<tuple<int,int>> zbs;
        const int m=grid.size(),n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    continue;
                int isize=0;
                zbs.push({i,j});
                grid[i][j]=0;
                isize++;
                while(!zbs.empty()){
                    int x,y;
                    tie(x,y)=zbs.front();
                    zbs.pop();
                    if(x-1>=0 && grid[x-1][y]==1){
                        grid[x-1][y]=0;
                        zbs.push({x-1,y});
                        isize++;
                    }
                    if(x+1<m && grid[x+1][y]==1){
                        grid[x+1][y]=0;
                        zbs.push({x+1,y});
                        isize++;
                    }
                    if(y-1>=0 && grid[x][y-1]==1){
                        grid[x][y-1]=0;
                        zbs.push({x,y-1});
                        isize++;
                    }
                    if(y+1<n && grid[x][y+1]==1){
                        grid[x][y+1]=0;
                        zbs.push({x,y+1});
                        isize++;
                    }
                }
                maxi=max(maxi,isize);
            }
        }
        return maxi;
    }
};