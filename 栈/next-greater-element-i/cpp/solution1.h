#include<vector>
using namespace std;
class Solution {
public:
/*
暴力查。。。
*/
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        for(int i=0;i<nums1.size();i++){
            int j=0;
            while(nums2[j]!=nums1[i]) j++;
            j++;
            int result=-1;
            for(;j<nums2.size();j++){
                if(nums2[j]<nums1[i])
                    continue;
                result=nums2[j];
                break;
            }
            results.push_back(result);
        }
        return results;
    }
};