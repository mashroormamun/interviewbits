class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();

        for(int i=0; i<n-1; i++) {
            int delta = prices[i+1]-prices[i];
            if(delta>0) profit += delta;
        }

        return profit;
    }
};
