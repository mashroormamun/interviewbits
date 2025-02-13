#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
private: 
    char getComplementaryParentheses(char c) {
        switch(c) {
            case '}':
                return '{';
            case ')':
                return '(';
            default:
                return '[';
        }
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(!st.empty()) {
                    char p = st.top();
        
                    if (p != getComplementaryParentheses(s[i])) {
                        return false;
                    }

                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution s;
    cout << "true: " << true << endl;
    cout << "false: " << false << endl;

    cout << s.isValid("]") << endl;
    return 0;
}