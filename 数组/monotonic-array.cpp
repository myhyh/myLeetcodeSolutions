class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const int n=A.size();
        int st=A.front(),ed=A.back();
        int cha=st-ed;
        if(cha>0){
            for(int i=1;i<n;i++){
                if(A[i]>A[i-1])
                    return false;
            }
        }else if(cha<0){
            for(int i=1;i<n;i++){
                if(A[i]<A[i-1])
                    return false;
            }
        }else{
            for(int i=1;i<n;i++){
                if(A[i]!=A[i-1])
                    return false;
            }
        }
        return true;
    }
};