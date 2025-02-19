#include<unordered_map>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool comp(vector<int>& p1, vector<int>& p2) {
        
        if(p1[0]==p2[0]) {
            if(p1[1]>p2[1]) return true;
        }

        if(p1[0]<p2[0]) return true;
        
        return false;

    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);

        for(int i=0;i<envelopes.size();i++) {
            cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
        }

        return 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> envelopes{{6,4},{2,9},{5,4},{2,3},{6,7}};
    
    s.maxEnvelopes(envelopes);

    return 0;
}