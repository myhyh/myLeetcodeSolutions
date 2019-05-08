class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(msmax(A,L,M),msmax(A,M,L));
    }
    
    int msmax(vector<int>& A, int L, int M){
        const int n=A.size();
        int* Lm=new int[n](),*Mm=new int[n]();
        for(int i=0;i<L;i++)
            Lm[0]+=A[i];
        for(int i=L;i<n;i++){
            Lm[i-L+1]=Lm[i-L]-A[i-L]+A[i];
        }
        for(int i=L;i<n;i++){
            Lm[i-L+1]=max(Lm[i-L+1],Lm[i-L]);
        }
        for(int i=0;i<M;i++)
            Mm[0]+=A[i];
        for(int i=M;i<n;i++){
            Mm[i-M+1]=Mm[i-M]-A[i-M]+A[i];
        }
        for(int i=n-1;i>=M;i--){
            Mm[i-M]=max(Mm[i-M+1],Mm[i-M]);
        }
        
        int mmax=0;
        for(int i=0;i<=n-L-M;i++){
            mmax=max(mmax,Lm[i]+Mm[i+L]);
        }
        return mmax;
    }
};