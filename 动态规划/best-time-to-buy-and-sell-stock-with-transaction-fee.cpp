class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n=prices.size();
        int cash=0,hold=-prices[0];     //cash:手上没有股票时的最大收益，hold:手上有股票时的最大收益
        for(int i=1;i<n;i++){
            int ohold=hold,ocash=cash;
            hold=max(ohold,ocash-prices[i]);
            cash=max(ocash,ohold+prices[i]-fee);
        }
        return cash;
    }
};