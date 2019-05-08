class Solution {
public://递归
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return helper(candidates,0,target);
    }
    
    vector<vector<int>> helper(vector<int>& candidates,int start,int target){
        vector<vector<int>> res;
        int times=0;
        if(target==0)
            return {{}};
        if(start>=candidates.size())
            return {};
        
        while(target>=0){
            auto tmp=helper(candidates,start+1,target);
            for(auto &v:tmp)
                for(int i=0;i<times;i++)
                    v.push_back(candidates[start]);
            target-=candidates[start];
            times++;
            move(tmp.begin(),tmp.end(),back_inserter(res));
        }
        return res;
    }
};

