class Solution {
public:
//空间更省
    int numberOfArithmeticSlices(vector<int>& A) {
        const int n=A.size();
        int maxlen=0;
        int sum=0;
        for(int i=2;i<n;i++){
            if(A[i-1]-A[i-2]==A[i]-A[i-1]){
                maxlen++;
                sum+=maxlen;
            }else{maxlen=0;}
        }
        return sum;
    }
};