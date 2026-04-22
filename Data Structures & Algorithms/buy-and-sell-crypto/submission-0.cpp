class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = prices[0];
        int value = 0;
        for(int sell : prices){
            value = max(value, sell-minbuy);
            minbuy = min(minbuy,sell);
        }
        return value;
    }
};
