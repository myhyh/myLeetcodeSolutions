class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return cs3(k,n,1);
    }
    
    vector<vector<int>> cs3(int k,int n,int s){
        if(k==0){
            if(n==0)
                return {{}};
            return {};
        }
        if(n<=0){
            return {};
        }
        if(s==10){
            return {};
        }
        auto result1=cs3(k-1,n-s,s+1);
        for(auto& v:result1){
            v.push_back(s);
        }
        auto result2=cs3(k,n,s+1);
        move(result2.begin(),result2.end(),back_inserter(result1));
        return result1;
    }
};