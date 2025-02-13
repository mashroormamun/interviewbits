#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidParenthesis(char p) {
        switch(p) {
            case '(':
            case '[':
            case '{':
            case ')':
            case '}':
            case ']':
                return true;
            default: 
                return false;
        }
    }

    bool isLeftParenthesis(char p) {
        switch(p) {
            case '(':
            case '[':
            case '{':
                return true;
            default: 
                return false;
        }
    }

    char getCounterParenthesis(char p) {
        switch(p) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
        }

        return ' ';
    }

    bool isValid(string s) {
        stack<char> q;

        for (int i=0 ; i<s.length() ; i++) {
            if (isValidParenthesis(s[i])) {
                if (isLeftParenthesis(s[i])) {
                    q.push(s[i]);
                } else {
                    if (q.empty()) return false;
                    
                    if(getCounterParenthesis(s[i]) == q.top()) {
                        q.pop();
                        continue;
                    }

                    return false;
                }
            } else {
                return false;
            }
        }

        return q.empty();
       
    }
};

int main() {
    Solution s;
    // vector<string> strs = {"cir", "car"};

    auto result = s.isValid("(){()}}}");
    
    cout << "=====================" << endl;
    cout << result << endl;
    cout << "=====================" << endl;
    
    return 0;
}