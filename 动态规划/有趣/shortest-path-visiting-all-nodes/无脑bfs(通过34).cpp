class Solution {
public:
    
    struct state{
        int pos;
        vector<bool> visited;
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<state> q;
        const int n=graph.size();
        vector<bool> tmp(n);
        for(int i=0;i<n;i++){
            tmp[i]=true;
            q.push({i,tmp});
            tmp[i]=false;
        }
        int layer=0;
        while(!q.empty()){
            int size=q.size();
            for(int p=0;p<size;p++){
                state& s=q.front();
                if(count(s.visited.begin(),s.visited.end(),true)==n)
                    goto end;
                for(int i:graph[s.pos]){
                    state s_=s;
                    s_.visited[i]=true;
                    s_.pos=i;
                    q.push(s_);
                }
                q.pop();
            }
            layer++;
        }
        end:
        return layer;
    }
};