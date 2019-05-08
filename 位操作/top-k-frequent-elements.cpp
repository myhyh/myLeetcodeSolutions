class Solution {
public:
    class Comp{
        public:
        size_t operator()(pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cache;
        for(int i:nums){
            cache[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> qu;
        for(auto pa:cache){
            qu.push(pa);
            if(qu.size()>k)
                qu.pop();
        }
        vector<int> result(k);
        int idx=k-1;
        while(!qu.empty()){
            result[idx]=qu.top().first;
            idx--;
            qu.pop();
        }
        return result;
    }
};