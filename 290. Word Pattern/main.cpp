#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int start=0, end=0;
        bool isWord = false;
        string map[26]={};
        int s_len = s.length();
        int p_len = pattern.length();
        set<string> set;

        vector<string> tokens;

        for(int i=0; i<s_len; i++) {
            // cout << s[i] << endl;
            if((s[i]==' ') || ((i+1) == s_len)) {
                if(s[i]==' ') end = i-1;
                else end = s_len-1;

                string word = s.substr(start, (end-start+1));
                start = i+1;
                // cout << word << endl;

                tokens.push_back(word);
                if(tokens.size() > p_len) return false;
            }
        }

        if(tokens.size() != p_len) return false;

        for(int i=0; i<p_len; i++) {
            if(map[pattern[i]-'a'] == "") {
                map[pattern[i]-'a'] = tokens[i];

                auto pt = set.insert(tokens[i]);
                if (pt.second == false) return false;

                // cout << map[pattern[i]-'a'] << " = "<<  tokens[i] << endl;

            } else if (map[pattern[i]-'a'] != tokens[i]) {
                // cout << map[pattern[i]-'a'] << " != "<<  tokens[i] << endl;
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.wordPattern("jquery", "jquery") << endl;;
    return 0;
}