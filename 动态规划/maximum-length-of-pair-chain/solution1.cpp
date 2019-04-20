class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //贪心法,始终使得查找上限最小那肯定是最好的
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int maxp=0x80000000;
        const int n=pairs.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(pairs[i][0]>maxp){
                maxp=pairs[i][1];
                res++;
            }
        }
        return res;
    }
};