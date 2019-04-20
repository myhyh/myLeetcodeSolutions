class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(),A.end(),0);
        if(sum%3!=0)
            return false;
        int psum=sum/3;
        int ps=0;
        int parts=0;
        for(int i:A){
            ps+=i;
            if(ps==psum){
                ps=0;
                parts++;
            }
        }
        return parts==3;
    }
};