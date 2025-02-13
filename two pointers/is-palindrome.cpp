class Solution {
public:

bool isAlphNumeric(char c) {
    if (c>='a' && c<='z') return true;
    if (c>='A' && c<='Z') return true;
    if (c>='0' && c<='9') return true;

    return false;
}

char toLowerCase(char c) {
    if(c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');

    return c;
}

bool isSameChar(char a, char b) {
    if (a==b) return true;

    if(toLowerCase(a) == toLowerCase(b)) return true;

    return false;
}

bool isPalindrome(string s) {
    int left=0;
    int right=s.length()-1;

    while(left<right) {
        // cout << left << right << endl;
        while(!isAlphNumeric(s[left])) {
            left++;
        }

        while(!isAlphNumeric(s[right])) {
            right--;
        }

        if(left>=right) break;

        if(!isSameChar(s[left], s[right])) {
            return false;
        }

        // cout << s[left] << " " << s[right] << endl;

        left++;
        right--;
    }   

    return true;
}
};

