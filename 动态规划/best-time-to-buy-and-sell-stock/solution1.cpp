class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int *hmax=new int[prices.size()];
        for(int i=prices.size()-1;i>=0;i--){
            if(i==prices.size()-1 || prices[i]>hmax[i+1]){
                hmax[i]=prices[i];
            }else{
                hmax[i]=hmax[i+1];
            }
        }
        int qmin=0x7fffffff;
        int maxp=0;
        for(int i=0;i<prices.size();i++){
            qmin=min(prices[i],qmin);
            maxp=max(maxp,hmax[i]-qmin);
        }
        return maxp;
    }
};