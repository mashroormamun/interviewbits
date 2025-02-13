#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string &a) {
        int len = a.length();

        for(int i=0; i<len/2; i++) {
            char temp = a[i];
            a[i] = a[len-1-i];
            a[len-1-i] = temp;
        }

        return a;
    }

    int getNum(char c) {
        return c-'0';
    }

    char toChar(int i) {
        return i+'0';
    }

    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();

        if(len_a==0) return b;
        if(len_b==0) return a;

        reverseString(a);
        reverseString(b);

        string res = "";
        int carry = 0;

        int i;
        for(i=0; i<len_a && i<len_b; i++) {
            int sum = getNum(a[i]) + getNum(b[i]) + carry;
            res += toChar(sum%2);
            carry = sum/2;
        }

        if (i<len_a) {
            for(; i<len_a; i++) {
                int sum = getNum(a[i]) + carry;
                res += toChar(sum%2);
                carry = sum/2;
            }
        }

        if (i<len_b) {
            for(; i<len_b; i++) {
                int sum = getNum(b[i]) + carry;
                res += toChar(sum%2);
                carry = sum/2;
            }
        }

        if (carry != 0) 
            res += toChar(1);

        reverseString(res);

        return res;
        
    }
};


int main() { 
    Solution s;
    cout << s.addBinary("111", "1") << endl;

    return 0;
}