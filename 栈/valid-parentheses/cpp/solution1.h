#include<string>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char,char> cur_map{
            {')','('},
            {']','['},
            {'}','{'}
        };
        for(char c:s){
            if(c==')' || c=='}' || c==']'){
                if(stk.empty())
                    return false;
                if(cur_map[c]!=stk.top())
                    return false;
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};