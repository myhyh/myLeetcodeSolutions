class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n=nums.size();
        vector<int> imme;
        imme.reserve(n);
        vector<vector<int>> res;
        subs(n,0,nums,imme,res);
        return res;
    }
    
    void subs(int n,int begin,vector<int>& nums,vector<int> &imme,vector<vector<int>>& res){
        if(n==begin){
            res.push_back(imme);
            return;
        }
        imme.push_back(nums[begin]);
        subs(n,begin+1,nums,imme,res);
        imme.pop_back();
        subs(n,begin+1,nums,imme,res);
    }
};