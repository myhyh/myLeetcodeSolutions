class Solution {
public:
//递归解法
    vector<string> letterCasePermutation(string S) {
        return lcp(S,0);
    }
    vector<string> lcp(string &S,int st){
        if(st>=S.size())
            return {S};
        if(isalpha(S[st])){
            auto res=lcp(S,st+1);
            char stp;
            if(isupper(S[st])){
                stp=tolower(S[st]);
            }else{
                stp=toupper(S[st]);
            }
            vector<string> tmp;
            for(auto s:res){
                s[st]=stp;
                tmp.emplace_back(s);
            }
            move(tmp.begin(),tmp.end(),back_inserter(res));
            return res;
        }
        return lcp(S,st+1);
    }
};


class Solution {
public:
    //迭代解法
    vector<string> letterCasePermutation(string S) {
        int prior_size;
        vector<string> result;
        result.push_back(S);
        for(int i = 0; i < S.size(); i++)
        {
            char changed=0;
            if (S[i] >= 'a' && S[i] <= 'z')
            {
                changed=S[i] + ('A'-'a');
            }else if (S[i] >= 'A' && S[i] <= 'Z'){
                changed=S[i] - ('A'-'a');
            }
            if(!changed)
                continue;
            prior_size = result.size();
            for(int j = 0; j < prior_size; j++)
            {
                result.push_back(result[j]);
                result[j][i] = changed;
            }
        }
        return result;
    }
};