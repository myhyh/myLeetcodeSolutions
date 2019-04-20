class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> tcosts(n+1);
        if(n<2)
            return 0;
        cost.push_back(0);
        tcosts[0]=cost[0];
        tcosts[1]=cost[1];
        for(int i=2;i<=n;i++){//0 1 2... 伪     0 1 2 ...
            tcosts[i]=min(tcosts[i-1],tcosts[i-2])+cost[i];
        }
        return tcosts[n];
    }
};