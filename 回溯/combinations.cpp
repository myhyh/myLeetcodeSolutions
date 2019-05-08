class Solution {
public://类似bfs的递归
    vector<vector<int>> combine(int n, int k) {
        if(k==n){
            vector<int> tmp;
            for(int i=1;i<=n;i++){
                tmp.push_back(i);
            }
            return {tmp};
        }
        
        if(k==0){
            return {{}};
        }
        
        auto res1=combine(n-1,k);
        auto res2=combine(n-1,k-1);
        for(auto &v:res2){
            v.push_back(n);
        }
        move(res2.begin(),res2.end(),back_inserter(res1));
        return res1;
    }
};

class Solution {
public://类似dfs的递归,速度加快
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res,tmp,n,k);
        return res;
    }
    
    void helper(vector<vector<int>> &res,vector<int> &tmp,int n,int k){
        if(k==0){
            res.push_back(tmp);
            return;
        }
        if(n<k){
            return;
        }
        helper(res,tmp,n-1,k);
        tmp.push_back(n);
        helper(res,tmp,n-1,k-1);
        tmp.pop_back();
    }
};