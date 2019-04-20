class Solution {
public:
    bool isjew[52];
    int numJewelsInStones(string J, string S) {
        for(char c:J){
            if(c>='a' && c<='z'){
                isjew[c-'a']=true;
            }else{
                isjew[c-'A'+26]=true;
            }
        }
        int res=0;
        for(char c:S){
            if(c>='a' && c<='z'){
                if(isjew[c-'a'])
                    res++;
            }else{
                if(isjew[c-'A'+26])
                    res++;
            }
        }
        return res;
    }
};