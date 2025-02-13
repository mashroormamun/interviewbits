class Solution {
public:
    int squareSum(int num) {
        int sum = 0;

        while(num>0) {
            int digit = num%10;
            sum += digit*digit;

            num /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> m;

        while(true) {
            int s_sum = squareSum(n);
            
            if (s_sum==1) return true;

            if (m.find(s_sum) != m.end()) {
                return false;
            }

            m[s_sum] = 1;
            n = s_sum;
        }

        return false;
    }
};
