class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        const int n=A.size();
        vector<int> result;
        for(int i=n;i>1;i--){
            int mi=max_element(A.begin(),A.begin()+i)-A.begin();
            if(mi==i-1)
                continue;
            reverse(A.begin(),A.begin()+mi+1);
            result.push_back(mi+1);
            reverse(A.begin(),A.begin()+i);
            result.push_back(i);
        }
        return result;
    }
};