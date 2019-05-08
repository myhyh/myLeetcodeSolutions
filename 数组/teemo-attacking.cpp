class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        const int n=timeSeries.size();
        int res=0;
        for(int i=0;i<n-1;i++){
            int realdur=timeSeries[i+1]-timeSeries[i];
            res+=realdur>duration?duration:realdur;
        }
        if(n>=1)
            res+=duration;
        return res;
    }
};