class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int m=s.size(),n=p.size();
        if(m<n)
            return {};
        int cs[26]={0};
        for(char c:p)cs[c-'a']++;
        for(int i=0;i<n-1;i++){
            cs[s[i]-'a']--;
        }
        vector<int> res;
        for(int i=n-1;i<m;i++){
            
            cs[s[i]-'a']--;
            int j=0;
            for(;j<26;j++)
                if(cs[j]!=0)
                    break;
            if(j==26){
                res.push_back(i-n+1);
            }
            cs[s[i-n+1]-'a']++;
            
        }
        return res;
    }
};