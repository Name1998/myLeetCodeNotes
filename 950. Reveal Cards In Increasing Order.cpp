
//模拟翻牌过程（正向）
//实际翻牌：已知手牌，未知结果
//模拟操作：未知手牌(result)，已知结果(increasing deck)
//思路：把翻牌时的赋值操作逆转即可，即结果->手牌
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(),deck.end());
    int n = deck.size();
    queue<int> index;
    vector<int> result(n);
    //vector<int> result[n]; //WRONG,此操作为创建了一个存了n个vector的普通数组
    //result[0].push_back(1);
    for(int i=0; i<n; i++)
        index.push(i);
    for(int i=0; i<n; i++){
        result[index.front()] = deck[i];        //轮到翻牌时，翻出的一定是递增序的
        index.pop();
        if(!index.empty()){
            index.push(index.front());
            index.pop();
        }
    }
    return result;
}
