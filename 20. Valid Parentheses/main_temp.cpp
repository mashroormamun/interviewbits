#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isLeftParenthesis(char p) {
        switch(p) {
            case '{':
            case '(':
            case '[':
                return true;
        }

       return false;
    }

    char getCounterParenthesis(char p) {
        switch(p) {
            case '}':
                return '{';
            case ')':
                return '(';
            case ']':
                return '[';
        }

       return 'a';
    }

    bool isValid(string s) {
        stack<char> stack;

        for(int i=0;i<s.length();i++) {
            if(isLeftParenthesis(s[i])) {
                stack.push(s[i]);
            } else {
                if(!stack.empty()) {
                    if(stack.top() != getCounterParenthesis(s[i])) {
                        return false;
                    } 
                    
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution s;
    // vector<string> strs = {"cir", "car"};

    //(){()}}}
    auto result = s.isValid("");
    
    cout << "=====================" << endl;
    cout << result << endl;
    cout << "=====================" << endl;
    
    return 0;
}