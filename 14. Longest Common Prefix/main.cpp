#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        bool shouldBreak = false;

        for (int i=0; ; i++) {
            for (int j=0 ; j<strs.size() ; j++) {
                if (i == strs[j].length())
                    shouldBreak = true;
                    break;
            }

            if (shouldBreak) break;

            char ch = strs[0][i];
            bool match = true;

            for (int j=0 ; j<strs.size() ; j++) {
                if (ch != strs[j][i]) {
                    match = false;
                    shouldBreak = true;
                    break;
                }
            }

            if(match) result += ch;
        }
                
        return result;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"cir", "car"};

    auto result = s.longestCommonPrefix(strs);
    
    cout << "=====================" << endl;
    cout << result << endl;
    cout << "=====================" << endl;
    
    return 0;
}