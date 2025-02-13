class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<int>> m;

        for(int i=0;i<strs.size();i++) {
            string s = strs[i];
            sort(s.begin(), s.end());

            m[s].push_back(i);
        }

        for (auto it=m.begin(); it!= m.end(); it++) {
            // std::cout << it->first << std::endl;

            auto x = it->second;
            vector<string> r;

            for (auto q=x.begin(); q!= x.end(); q++) {
                // std::cout << *q << std::endl;
                r.push_back(strs[*q]);
            }

            res.push_back(r);
        }

        return res;
    }
};

