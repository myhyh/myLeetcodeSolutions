class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int n=A.size();
        vector<int> result(n);
        auto idx=result.end()-1;
        for(auto p=A.begin(),q=A.end()-1;p<=q;){
            if(abs(*p)>abs(*q)){
                *(idx--)=*p**p;
                p++;
            }else{
                *(idx--)=*q**q;
                q--;
            }
        }
        return result;
    }
};