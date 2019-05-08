class Solution {
public:
//先得把0换到数组最前面,这样排序过的前半部分数组的最大值+1换到后面,依次类推
    int maxChunksToSorted(vector<int>& arr) {
        int maxi=0;
        int tofind=0;
        int cnt=0;
        int res=0;
        const int n=arr.size();
        bool found=false;
        for(int i=0;i<n;i++){
            cnt++;
            maxi=max(maxi,arr[i]);
            
            if(arr[i]==tofind){
                found=true;
            }
            
            if(found && cnt==maxi-tofind+1){
                cnt=0;
                tofind=maxi+1;
                res++;
            }
        }
        return res;
    }
};