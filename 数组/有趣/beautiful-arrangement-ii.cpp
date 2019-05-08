class Solution {
public:

    //这道题要点在于找规律,需要k个不同的差则可以先从[1-n]的两头取,填入[1,n,2,n-1,3,...],发现差分别是n-1,n-2,n-3,...
    //中间正好留下了一个连续区间,前面凑够k-1个不同的差之后,就把连续区间放在后面,差都是1,就有k个不同的差了
    vector<int> constructArray(int n, int k) {
        bool up=true;
        vector<int> result(n);
        int l=1,r=n;
        int i=0;
        for(;i<k;i++){
            if(up){
                result[i]=l++;
            }else{
                result[i]=r--;
            }
            up=!up;
        }
        if(up)
            while(i<n)
                result[i++]=r--;
        else
            while(i<n)
                result[i++]=l++;
        return result;
    }
};