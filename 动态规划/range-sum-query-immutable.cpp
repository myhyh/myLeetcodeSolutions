class NumArray {
public:
    vector<int> myvec;
    vector<int> sums;
    NumArray(vector<int>& nums):myvec(nums.size()+1){
        for(int i=0;i<nums.size();i++){
            myvec[i+1]=myvec[i]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return myvec[j+1]-myvec[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */