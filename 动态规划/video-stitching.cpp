class Solution {        // 10:11-
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int step = 0, furthest = 0;
        for (int i=0, nex_furthest=furthest; i<clips.size();) {
            if (clips[i][0] > furthest) return -1;
            for (; i<clips.size() && clips[i][0]<= furthest; ++i) 
                nex_furthest = max(nex_furthest, clips[i][1]);
            furthest = nex_furthest;
            // cout << furthest << ", " << i << endl;
            ++step;
            if (furthest >= T) return step? step: -1;
        }
        return -1;
    }
};