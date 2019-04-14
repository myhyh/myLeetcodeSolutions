#include<iostream>
#include"solution1.h"
int main(){
    Solution s;
    vector<int> a{1,2,3,4,5};
    vector<int> b{4,5,3,2,1};
    cout<<s.validateStackSequences(a,b);
}