#include<iostream>
// #include<string>

using namespace std;

class Solution {
public:
    string convertToSuitableString(string s) {
        string res = "";
        for(int i=0; i<s.size(); i++) {
            if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||  (s[i]>='0' && s[i]<='9')) {
                if(s[i]>='a' && s[i]<='z') {
                    res += s[i] - 'a' + 'A';
                } else {
                    res += s[i];
                }
            }
        }

        return res;
    }

    bool isPalindrome(string s) {
        string ss = convertToSuitableString(s);
        for(int i=0; i<=ss.size()/2; i++) {
            if(ss[i] != ss[ss.size()-1-i]) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(" ") << endl;

    return 0;
}