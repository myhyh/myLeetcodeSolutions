#include"solution1.h"
#include<iostream>
#include<string>
#include<sstream>


int main(){
    Solution s;
    vector<int> a{4,1,2};
    vector<int> b{1,3,4,2};

    for(auto ele:s.nextGreaterElement(a,b)){
        cout<<ele<<" ";
    }
}