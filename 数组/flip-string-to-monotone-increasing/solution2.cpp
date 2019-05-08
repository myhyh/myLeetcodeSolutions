class Solution {
public:
    //zeros:前面有几个1需要翻转
    int minFlipsMonoIncr(string S) {
        int one = 0, zeros = 0;
        
        for (int i = 0; i < S.size(); ++i) {
            one = min(one, zeros) + (S[i] == '0');
            zeros += S[i] == '1';
        }
        
        return min(one, zeros);
        
    }
    
};