class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        bool isWord = false;
        int wordLen = 0;

        for (int i=len-1 ; i>=0 ; i--) {
            if (s[i] != ' ') {
                isWord = true;
                wordLen++;
            }

            if (isWord && (s[i]==' ' || i==0)) {
                return wordLen;
            }
        }

        return wordLen;
    }
};
