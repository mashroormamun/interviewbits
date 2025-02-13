class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1;
        int p = 0;

        while(r<prices.size()) {
            int profit = prices[r] - prices[l];

            if(profit > 0) {
                p = profit > p ? profit : p;
                r++;
            } else {
                l = r;
                r++;
            }
        }

        return p;

    }
};

