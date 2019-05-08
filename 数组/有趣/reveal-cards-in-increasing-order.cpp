class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //要求按照某种操作得到新的序列，倒着操作一遍就是原来的序列了
        deque<int>d;
        sort(deck.begin(),deck.end(),greater<int>());
        for(const auto& i:deck)
        {
            if(d.empty()==false)
            {
                d.emplace_front(d.back());
                d.pop_back();
            }
            d.emplace_front(i);
        }
        return vector<int>(d.cbegin(),d.cend());
    }
};