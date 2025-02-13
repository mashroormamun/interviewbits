#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int calculate(int num1, int num2, char token) {
        switch(token) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        };

        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i] == "+" || 
            tokens[i] == "-" || 
            tokens[i] == "*" || 
            tokens[i] == "/") {
                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                int res = calculate(num1, num2, tokens[i][0]);
                st.push(res);
            } else {
                cout << tokens[i] << endl;
                int number = stoi(tokens[i]);
                st.push(number);
            }

        }

        return st.top();
    }
};


int main() {
    Solution s;
    vector<string> input{"1","2","+","3","*","4","+"};
    
    cout << s.evalRPN(input) << endl;
    return 0;
}