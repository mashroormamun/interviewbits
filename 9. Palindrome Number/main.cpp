#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int reverseNum = 0;
        int num = x;
        while (x > 0) {
            reverseNum = reverseNum * 10 + (x%10);
            x /= 10;
        }

        if (num == reverseNum) {
            return true;
        }

        return false;
    }
};

int main() {
    printf("hello world\n");

    Solution s;
    auto result = s.isPalindrome(12345664321);

    cout << result << endl;

    return 0;
}