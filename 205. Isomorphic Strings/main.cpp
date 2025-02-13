#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        if (s_len != t_len) return false;

        unordered_map<char, char> m;

        for (int i=0; i<s_len; i++) {
            auto it = m.find(s[i]);
            if (it == m.end()) {
                m[s[i]] = t[i];
            } else {
                if (m[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("egg", "436") << endl;

    return 0;
}