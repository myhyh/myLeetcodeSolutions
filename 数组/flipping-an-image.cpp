class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        //注意:这里auto&的&是不可或缺的
        for(auto &row:A){
            int n=row.size();
            for(int i=0,j=n-1;i<j;i++,j--){
                swap(row[i],row[j]);
            }
        }
        for(auto &row:A)
            for(auto& num:row)
                num=num==0?1:0;
        return A;
    }
};