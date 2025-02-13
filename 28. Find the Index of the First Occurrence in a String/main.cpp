class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHay = haystack.length();
        int lenNeed = needle.length();

        if (lenHay < lenNeed) return -1;

        for (int i=0 ; i<=lenHay-lenNeed ; i++) {
            if(haystack[i] != needle[0]) continue;

            for (int j=0 ; j<lenNeed ; j++) {
                if(haystack[i+j] != needle[j]) break;

                if (j == lenNeed-1) return i;
            }

        }

        return -1;
    }
};
