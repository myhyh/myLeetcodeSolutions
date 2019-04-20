class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        //利用类似hash的思想对字母出现的次数进行统计,反正最后输出顺序不限定
        int* resChars=new int[26];
        int* turnChars=new int[26];
        vector<string> res;
        if(A.empty())
            return res;
        const int n=A.size();
        for(int i=0;i<26;i++)
            resChars[i]=0x7fffffff;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++)
                turnChars[j]=0;
            for(char c:A[i])
                ++turnChars[c-'a'];
            for(int j=0;j<26;j++)
                resChars[j]=min(turnChars[j],resChars[j]);
        }
        for(int i=0;i<26;i++)
            for(int j=0;j<resChars[i];j++){
                string s;
                s.push_back('a'+i);
                res.push_back(s);
            }
        return res;
    }
};