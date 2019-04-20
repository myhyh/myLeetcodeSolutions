class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        const int n=A.size();
        vector<int> newArr(n);
        
        int p=0;
        for(int i:A){
            if(i%2==0)
                newArr[p++]=i;
        }
        for(int i:A){
            if(i%2==1)
                newArr[p++]=i;
        }
        return newArr;
    }
};