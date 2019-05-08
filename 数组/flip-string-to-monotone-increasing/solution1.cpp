class Solution {
public:
//对一个位置,数一下前面有几个1,后面有几个0,加起来取最小可得最小翻转次数
    int minFlipsMonoIncr(string S) {
        const int n=S.size();
        vector<int> ys(n+1);
        vector<int> os(n+1);
        for(int i=1;i<n+1;i++){
            if(S[i-1]=='1')
                ys[i]=ys[i-1]+1;
            else
                ys[i]=ys[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(S[i]=='0')
                os[i]=os[i+1]+1;
            else
                os[i]=os[i+1];
        }
        int res=0x7fffffff;
        for(int i=0;i<n+1;i++){
            res=min(res,ys[i]+os[i]);
        }
        return res;
    }
};