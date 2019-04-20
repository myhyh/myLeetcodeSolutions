class Solution {
public:
    int dp[2000];
    bool divisorGame(int N) {
        vector<int> divs;
        for(int Nz=1;Nz<=N;Nz++){
            
            divs.clear();
            int Nb=Nz;
            for(int i=1;i<Nb;i++){
                if(Nb%i==0){
                    if(dp[Nz-i]==1){
                        dp[Nz]=2;
                        goto cont;
                    }
                    divs.push_back(i);
                }
                while(Nb%i==0 && i!=1)
                    Nb/=i;
            }
            dp[Nz]=1;
            cont:;
        }
        return dp[N]==2;
    }
    Solution(){
        for(int i=0;i<2000;i++)
            dp[i]=0;
        dp[0]=1;
    }
};