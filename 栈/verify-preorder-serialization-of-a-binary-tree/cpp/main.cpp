#include"solution1.h"
#include<iostream>
int main(){
    Solution s;
    std::cout<<s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")<<"\n";
    cout.flush();
    std::cout<<s.isValidSerialization("1,#")<<"\n";
    cout.flush();
    std::cout<<s.isValidSerialization("9,#,#,1")<<"\n";
}