class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int M=prices[0],m=prices[0];
        int profit=0;
        for(int i:prices){
            if(i<M){
                profit+=M-m;
                M=i;
                m=i;
            }else{
                M=i;
            }
        }
        profit+=M-m;
        return profit;
    }
};