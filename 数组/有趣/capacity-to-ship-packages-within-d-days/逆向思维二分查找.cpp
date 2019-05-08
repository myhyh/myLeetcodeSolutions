class Solution {
public:
    //假定船的大小在left和right之间,二分查找最合适的大小,需要的船过多则增大left,否则减小right
    int shipWithinDays(vector<int>& weights, int D) {
        int left=0,right=accumulate(weights.begin(),weights.end(),0);
        while(left<right){
            int mid=(left+right)/2;
            int cur=0,ships=1;
            for(int i:weights){
                if(i>mid){
                    ships=D+1;
                    break;
                }
                if(cur+i>mid){
                    ships++;
                    cur=0;
                }
                cur+=i;
            }
            if(ships>D)
                left=mid+1;
            else{
                right=mid;
            }
        }
        return left;
    }
};