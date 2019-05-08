class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp;
        tmp.resize(2*n);
        genstr(n,0,0,tmp,result);
        return result;
    }
    
    void genstr(int n,int l,int r,string &tmp,vector<string>& res){
        if(l==n && r==n){
            res.push_back(tmp);
            return;
        }
        if(l<n){
            tmp[l+r]='(';
            genstr(n,l+1,r,tmp,res);
        }
        if(l-r>0){
            tmp[l+r]=')';
            genstr(n,l,r+1,tmp,res);
        }
    }
};