#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverse(string& s, int start, int end) {
        int middle = (start+end)/2;

        for(int i=start; i<=middle; i++) {
            char temp = s[i];
            s[i] = s[end-i+start];
            s[end-i+start] = temp;
        }

        return s.substr(start, end-start+1);
    }

    string reverseWords(string s) {
        string result = "";
        reverse(s, 0, s.size()-1);
        
        bool isWord = false;
        int start=0, end=0;


        for(int i=0; i<s.size(); i++) {
            if(!isWord && s[i] != ' ') {
                isWord = true;
                start=i;
            }

            if(isWord && (s[i] == ' ' || i==s.size()-1)) {
                if (s[i] == ' ' ){
                    end=i-1;
                } else if(i==s.size()-1) {
                    end=i;
                } 

                isWord = false;
                if (result != "") result += " ";
                result += reverse(s, start, end);
                // cout << start << " " << end << endl;

            }
        }
        
        return result;
    }
};

int main() {
    string str = " asdasd df f";

    Solution s;

    // s.reverse(str, 0, str.size()-1);
    // cout << str << endl;

    cout << s.reverseWords(str) << "|" << endl;

    return 0;
}