class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto i=numbers.begin(),j=numbers.end()-1;
        while(i<j){
            int sum=*i+*j;
            if(sum>target){
                j--;
            }else if(sum<target){
                i++;
            }else{
                break;
            }
        }
        vector<int> result(2);
        result[0]=i-numbers.begin()+1;
        result[1]=j-numbers.begin()+1;
        return result;
    }
};