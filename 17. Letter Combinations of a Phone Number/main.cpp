class Solution {
public:
    vector<string> result;

    void combination(string parent, string remaining_buttons, unordered_map<char, vector<char>>& m) {

        if(remaining_buttons.length()==0) {
            result.push_back(parent);
            return;
        }

        auto letters = m[remaining_buttons[0]];

        for(int i=0;i<letters.size();i++) {
            combination(parent+letters[i], remaining_buttons.substr(1,remaining_buttons.size()-1), m);
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return vector<string>{};

        unordered_map<char, vector<char>> m;

        m['2'] = vector<char> {'a','b','c'};
        m['3'] = vector<char> {'d','e','f'};
        m['4'] = vector<char> {'g','h','i'};
        m['5'] = vector<char> {'j','k','l'};
        m['6'] = vector<char> {'m','n','o'};
        m['7'] = vector<char> {'p','q','r', 's'};
        m['8'] = vector<char> {'t','u','v'};
        m['9'] = vector<char> {'w','x','y','z'};

        combination("", digits, m);

        return result;
        
    }
};
