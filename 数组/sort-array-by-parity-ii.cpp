class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0;
        vector<int> result(A.size());
        for(int a:A)
            if(a%2==0){
                result[i]=a;
                i+=2;
            }
        int j=1;
        for(int a:A)
            if(a%2==1){
                result[j]=a;
                j+=2;
            }
        return result;
    }
};