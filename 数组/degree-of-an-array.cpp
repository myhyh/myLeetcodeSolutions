class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,tuple<int,int,int>> nidx;
        const int n=nums.size();
        for(int i=0;i<n;i++){
            if(nidx.find(nums[i])==nidx.end()){
                nidx.insert({nums[i],{i,i,1}});
            }else{
                get<1>(nidx[nums[i]])=i;
                get<2>(nidx[nums[i]])+=1;
            }
        }
        int maxCnt=0;
        int minCha=0x7fffffff;
        for(auto pair:nidx){
            int m,M,cnt;
            tie(m,M,cnt)=pair.second;
            maxCnt=max(maxCnt,cnt);
        }
        for(auto pair:nidx){
            int m,M,cnt;
            tie(m,M,cnt)=pair.second;
            if(cnt==maxCnt)
                minCha=min(minCha,M-m);
        }
        return minCha+1;
    }
};