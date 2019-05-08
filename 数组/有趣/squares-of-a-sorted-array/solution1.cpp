class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(),A.end(),[](int a,int b){return abs(a)<abs(b);});
        for(auto& i:A)
            i=i*i;
        return A;
    }
};