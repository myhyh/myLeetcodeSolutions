class Solution {
public:
    
    struct state{
        int pos;
        unsigned int visited;
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<state> q;
        const int n=graph.size();
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
        }
        vector<vector<int>> dists(1<<n,vector<int>(n,0));
        int layer=0;
        int fres=(1<<n)-1;
        while(!q.empty()){
            int size=q.size();
            for(int p=0;p<size;p++){
                state s=q.front();
                q.pop();
                if(s.visited==fres)
                    goto end;
                if(dists[s.visited][s.pos]!=0)
                    continue;
                dists[s.visited][s.pos]=layer;
                for(int i:graph[s.pos]){
                    
                    state s_=s;
                    s_.visited|=1<<i;
                    
                    s_.pos=i;
                    q.push(s_);
                }
                
            }
            layer++;
        }
        end:
        return layer;
    }
};