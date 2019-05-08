#include<bits/stdc++.h>
using namespace std;

int pow(int base,int exp){
    int res=1;
    while(exp){
        if(exp&1)res=res*base;
        base=base*base;
        exp>>=1;
    }
    return res;
}
