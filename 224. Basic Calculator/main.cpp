#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNumber(char s) {
        return (s>='0' && s<='9');
    } 
    
    void evaluate(stack<string> &st) {
        string opr = "";
        int number = 0;
        bool isMinus = false;
        
        while(!st.empty()) {
            string t = st.top();
            st.pop();
            
            if(t=="-") {
                number = -number;
                // isMinus = true;
            }
            else if(t=="(") break;
            else if(t=="+") {}
            else {
                number += stoi(t);
            }
        }
        
        st.push(to_string(number));
    }
    
    int calculate(string s) {
        s = suitable_exp(s);
        cout << s << endl;

        stack<string> st;
        int number_left=-1;
        
        for(int i=0;i<s.length();i++) {
            if(isNumber(s[i])) {
                if(number_left==-1) {
                    number_left=i;
                }
            } else {
                if(number_left!=-1) {
                    string number = s.substr(number_left, i-number_left);
                    st.push(number);
                    number_left = -1;
                }
                
                if(s[i]=='(') {
                    string temp{s[i]};
                    st.push(temp);
                } else if(s[i] == ' ') {
                    continue;
                } else if(s[i]==')') {
                    evaluate(st);
                } else if(s[i]=='+') {
                    st.push("+");
                } else if(s[i]=='-') {
                    st.push("-");
                }
            }
        }

        if(number_left!=-1) {
            string number = s.substr(number_left, s.length()-number_left);
            st.push(number);
        }
        
        evaluate(st);
        
        
        return stoi(st.top());
    }
    
    string suitable_exp(string s) {
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        /*string m = "";

        bool isMinusWithNum = false;
        bool isMinusWithbracket = false;

        for(int i=0;i<s.length();i++) {
            if(s[i] == '-') {
                m.append("+(-");
                if(isNumber(s[i+1])) {
                    isMinusWithNum = true;
                } else if(s[i+1]=='(') {
                    isMinusWithbracket=true;
                }
            } else {
                string temp{s[i]};

                if(isMinusWithNum) {
                    if(!isNumber(s[i])) {
                        m.append(")"+temp);
                        isMinusWithNum=false;
                    } else {
                        m.append(temp);
                    }
                    
                } else if(isMinusWithbracket) {
                    
                    if(s[i]==')') {
                        m.append(temp+")");
                        isMinusWithbracket = false;
                    } else {
                        m.append(temp);
                    }
                } else {
                    m.append(temp);
                }
            }
        }

        return m;
        */

       return s;
    }
};

int main() {
    Solution s;
    string a = "1-(     -2)";

    cout << s.calculate(a) << endl;
    return 0;
}