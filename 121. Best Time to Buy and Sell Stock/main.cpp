class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int sum = 0;
        int n = prices.size();

        for (int i=0; i<n-1; i++) {
            int number = prices[i+1] - prices[i];
            sum += number;

            if(sum > max) max = sum;

            if(sum<0) {
                sum = 0;
            }
        }

        return max;
    }
};
