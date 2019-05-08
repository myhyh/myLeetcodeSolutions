class Solution {//暴力
public:
    int maxArea(vector<int>& hs) {
        int res=0;
        const int n=hs.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int h=min(hs[i],hs[j]);
                int a=h*(j-i);
                res=max(a,res);
            }
        }
        return res;
    }
};