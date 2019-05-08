class Solution {
public:
//快慢指针法寻找环,并寻找环的开头
    int findDuplicate(vector<int>& nums) {
        int* slow=&nums[0];
        int* fast=&nums[0];
        do{
            slow=&nums[*slow];
            fast=&nums[nums[*fast]];
        }while(slow!=fast);
        int* start=&nums[0];
        while(*start!=*slow){
            start=&nums[*start];
            slow=&nums[*slow];
        }
        return *slow;
    }
};