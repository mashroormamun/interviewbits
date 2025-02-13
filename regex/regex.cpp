#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    regex pattern("(BAT)(.*)");

    string s = "BATMAN";

    if(regex_match(s, pattern)) {
        cout << "match" << endl;
    }

    return 0;
}