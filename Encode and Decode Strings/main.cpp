#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";

        for(int i=0;i<strs.size();i++) {
            s+= to_string(strs[i].size()) + ";" + strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int start=0, end=0;

        for(int i=0;i<s.length();i++) {
            if(s[i]==';') {
                end = i-1;

                cout << start << " " << end-start+1 <<endl;
                int len = stoi(s.substr(start, end-start+1));
                string sub = s.substr(i+1, len);
                
                res.push_back(sub);

                start=i=i+len+1;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> input{"neet","code","love","you"};

    string r = s.encode(input);
    cout << r << endl;

    cout << "0123456789012345678901234567890123456789" << endl;


    s.decode(r);

    return 0;
}