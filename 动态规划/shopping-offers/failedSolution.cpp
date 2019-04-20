class Hasher{
    public:
    size_t operator()(const vector<int>& in) const{
        size_t result=0;
        auto ihash=hash<int>();
        for(int i:in){
            result^=ihash(i);
        }
        return result;
    }
};


class Solution {
public:
    unordered_map<vector<int>,int,Hasher> cache;
    int n;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=needs.size();
        return shoppingOffersRec(price,special,needs);
    }
    int shoppingOffersRec(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        //超时了........
        auto found=cache.find(needs);
        if(found!=cache.end())
            return found->second;
        bool allzero=true;
        for(int i=0;i<n;i++)
            if(needs[i]!=0){
                allzero=false;
                break;
            }
        if(allzero)
            return 0;
        int mincost=0x7fffffff;
        for(int i=0;i<n;i++){
            if(needs[i]!=0){
                needs[i]-=1;
                int result=shoppingOffersRec(price,special,needs);
                mincost=min(mincost,result+price[i]);
                needs[i]+=1;
            }
        }
        for(auto offer:special){
            bool buyable=true;
            for(int i=0;i<n;i++){
                if(needs[i]<offer[i]){
                    buyable=false;
                    break;
                }
            }
            if(buyable){
                for(int i=0;i<n;i++)
                    needs[i]-=offer[i];
                int result=shoppingOffersRec(price,special,needs);
                mincost=min(mincost,result+offer[n]);
                for(int i=0;i<n;i++)
                    needs[i]+=offer[i];
            }
        }
        return mincost;
    }
};