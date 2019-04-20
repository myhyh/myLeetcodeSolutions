class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> result(2);
        int ta=accumulate(A.begin(),A.end(),0);
        int tb=accumulate(B.begin(),B.end(),0);
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int cha=(tb-ta)/2;
        auto i=A.begin(),j=B.begin();
        while(i!=A.end() && j!=B.end()){
            if(*j<*i+cha)
                ++j;
            else if(*j>*i+cha)
                ++i;
            else{
                result[0]=*i;
                result[1]=*j;
                break;
            }
        }
        return result;
    }
};