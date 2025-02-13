#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int max_num=0;
        int left=0;


        for(int i=0;i<s.length();i++) {
            if(m.find(s[i])==m.end()) {
                m[s[i]]=i;
            } else {
                left= max(m[s[i]]+1, left);
                m[s[i]]=i;
            }

            cout << i <<" " <<left << endl;

            max_num = max_num > (i-left+1) ? max_num : (i-left+1);

            // cout << max <<" " <<left << endl;
        }

        return max_num;
     
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    return 0;
}