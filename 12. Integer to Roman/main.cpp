class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        while (num>0) {
            for(int i=val.size()-1 ; i>=0 ; i--) {
                if(num >= val[i]) {
                    res += roman[i];
                    num -= val[i];
                    break;
                }
            }
        }

        return res;
    }
};
