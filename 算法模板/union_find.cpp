#include<bits/stdc++.h>
using namespace std;

class uf{
    /*并查集
    可以把n个对象分成若干类,
    合并两个类别为一类union_,
    查找一个元素的类别根节点find,
    判断两个元素是否是一类same
    */
    vector<int> par;
public:
    uf(int n):par(n){
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int find(int i){
        if(par[i]!=i) par[i]=find(par[i]);
        return par[i];
    }
    void union_(int a,int b){
        a=find(a);
        b=find(b);
        par[a]=b;
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
};