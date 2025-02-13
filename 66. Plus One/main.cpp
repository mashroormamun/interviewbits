class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;

        digits[digits.size()-1]++;

        for(int i=digits.size()-1; i>=0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum%10;
            carry = sum/10;

            if(carry == 0) break;
        }

        if(carry == 0) return digits;

        digits.insert(digits.begin(), carry);
        return digits;

        // v.insert(v.begin(), 1, value)
    }
};
