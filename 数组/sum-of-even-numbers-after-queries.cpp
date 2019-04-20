class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int res=0;
        vector<int> ress(queries.size());
        for(int i:A){
            if(i%2==0)
                res+=i;
        }
        int resi=0;
        for(auto query:queries){
            int val=query[0],index=query[1];
            int vj=val%2;
            int sj=A[index]%2;

            if(sj &&vj){
                res+=A[index]+val;
            }else if(vj && !sj){
                res-=A[index];
            }else if(!vj && !sj){
                res+=val;
            }
            A[index]+=val;
            ress[resi++]=res;
        }
        return ress;
    }
};