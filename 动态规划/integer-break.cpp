class Solution {
public:
    int prods[100];
    int integerBreak(int n) {
        prods[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                prods[i]=max(prods[i],prods[i-j]*prods[j]);
                prods[i]=max(prods[i],(i-j)*prods[j]);
                prods[i]=max(prods[i],prods[i-j]*j);
                prods[i]=max(prods[i],(i-j)*j);
            }
        }
        return prods[n];
    }
};