class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val;

        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        
        int len = s.size();
        int sum = 0;

        for (int i=len-1; i>=0; i--) {
            sum += val[s[i]];

            if(i != (len-1)) {
                if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')) {
                    sum -= 2 * 1; 
                }

                if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')) {
                    sum -= 2 * 10; 
                }

                if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')) {
                    sum -= 2 * 100; 
                }
            }
        }

        return sum;
    }
};
