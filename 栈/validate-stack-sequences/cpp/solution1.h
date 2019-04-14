#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
/*
模拟栈的操作,不断push，直到可以pop则进行pop操作，如果过程出错则返回false
*/
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> emu;
        int pushidx=0;
        for(int i=0;i<popped.size();i++){
            while(emu.empty()||emu.top()!=popped[i]){
                if(pushidx>=pushed.size()){
                    return false;
                }
                emu.push(pushed[pushidx]);
                pushidx++;
            }
            emu.pop();
        }
        return emu.empty();
    }
};