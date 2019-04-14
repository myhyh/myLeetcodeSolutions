#include<string>
#include<stack>
using namespace std;
class Solution {
public:
/*
对于一个树的前序遍历，我们可以把非空节点和它的两个子树合成一个节点，然后用一个空节点替换掉，
这样的话最后只会剩下一个空节点，也就是原来的根节点，如果替换过程中出错，就说明不是合法的树前序遍历

下面用false表示非空节点，true表示空节点，遇到两个连续的空节点就说明上一个非空节点是合并过程中的树的叶节点
就可以和接下来连续的两个空节点合并成一个空节点
*/
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        stack<bool> stk;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]=='#'){
                if(stk.empty() ||stk.top()==false)
                    stk.push(true);
                else {
                    while(!stk.empty() && stk.top()==true){
                        stk.pop();
                        if(stk.empty())
                            return false;
                        stk.pop();
                    }
                    stk.push(true);
                }
                i++;
            }else{
                stk.push(false);
                while(i<preorder.size() && preorder[i]!=',')i++;
            }
        }
        return stk.size()==1 && stk.top()==true;
    }
};