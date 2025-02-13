#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag_len = magazine.length();
        int rans_len = ransomNote.length();

        if (mag_len<rans_len) return false;

        int m[26] = {0};

        for (int i=0; i<mag_len; i++) {
            m[magazine[i]-'a']++;
        }

        for (int i=0; i<rans_len; i++) {
            m[ransomNote[i]-'a']--;

            if (m[ransomNote[i]-'a'] < 0)
                return false;
        }

        return true;
    }
};

// TLE
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         int mag_len = magazine.length();
//         int rans_len = ransomNote.length();
//         if (mag_len<rans_len) return false;

//         sort(ransomNote.begin(), ransomNote.end());
//         sort(magazine.begin(), magazine.end());

//         int mag_index = 0;

//         for (int i=0; i<rans_len; i++) {
//             while(magazine[mag_index++] != ransomNote[i]) {
//                 if(mag_index == mag_len)
//                     return false;
//             }
//         }

//         return true;
//     }
// };

// Hash map accepted
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         int mag_len = magazine.length();
//         int rans_len = ransomNote.length();

//         if (mag_len<rans_len) return false;

//         unordered_map<char, int> m;
//         for (int i=0; i<mag_len; i++) {
//             m[magazine[i]]++;
//         }

//         for (int i=0; i<rans_len; i++) {
//             m[ransomNote[i]]--;

//             if (m[ransomNote[i]] < 0)
//                 return false;
//         }

//         return true;
//     }
// };

int main() {
    Solution s;
    cout << s.canConstruct("aa", "aab") << endl;

    return 0;
}