class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int n=A.size();
        int maxcnt=0;
        for(int i=-n+1;i<=n-1;i++){
            for(int j=-n+1;j<=n-1;j++){
                int asx,asy;
                int aex,aey;
                int bsx,bsy;
                int bex,bey;
                if(i<0){
                    asx=-i;aex=n; bsx=0;bex=n+i;
                }else{
                    asx=0;aex=n-i; bsx=i;bex=n;
                }
                if(j<0){
                    asy=-j;aey=n; bsy=0;bey=n+j;
                }else{
                    asy=0;aey=n-j; bsy=j;bey=n;
                }
                int cnt=0;
                for(int ax=asx,bx=bsx;ax<aex;ax++,bx++){
                    for(int ay=asy,by=bsy;ay<aey;ay++,by++){
                        if(A[ax][ay]==1&&B[bx][by]==1)
                            cnt++;
                    }
                }
                maxcnt=max(cnt,maxcnt);
            }
        }
        return maxcnt;
    }
};