class Solution {
public:
//两边较低的一边变高,总盛水面积才会增大,改变较高一端是没用的,所以从两边向里收缩即可
    int maxArea(vector<int>& hs) {
        int res=0;
        const int n=hs.size();
        int l=0,r=n-1;
        res=max(res,(r-l)*min(hs[r],hs[l]));
        while(l<r){
            int lo;
            if(hs[l]>hs[r]){
                lo=hs[r];
                while(hs[r]<=lo && l<r)r--;
                res=max(res,(r-l)*min(hs[r],hs[l]));
            }
            else{
                lo=hs[l];
                while(hs[l]<=lo && l<r)l++;
                res=max(res,(r-l)*min(hs[l],hs[r]));
            }
        }
        return res;
    }
};