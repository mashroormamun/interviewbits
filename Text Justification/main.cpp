#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> result;
        
        while(i<words.size()) {
            int char_count = 0;
            int letter_count = 0;
            vector<string> w;
            
            while(char_count<=maxWidth) {               
                char_count = char_count==0 ? char_count + words[i].length() : char_count + words[i].length() + 1;

                if(char_count <= maxWidth) {
                    w.push_back(words[i]);
                    letter_count += words[i].length();
                    i++;
                } else {
                    int space_needed = maxWidth-letter_count;
                    int space_count = w.size()-1;

                    string result_line = "";

                    if(space_count==0) {
                        result_line = w[0];

                        for(int q=0;q<space_needed;q++) {
                            result_line += " ";
                        }

                        // result_line += to_string(space_needed);
                    } else {
                        for(int j=0;j<w.size();j++) {
                            
                            result_line += w[j];
                            
                            // cout << space_count << " " << space_needed << endl;

                            int space_to_be_printed = 0;
                            
                            if(space_count!=0)
                                space_to_be_printed = (int)ceil((double)space_needed/(double)space_count);

                            for(int q=0;q<space_to_be_printed;q++) {
                                result_line += " ";
                            }

                            // result_line += to_string(space_to_be_printed);

                            space_needed -= space_to_be_printed;
                            space_count--;

                        }
                    }

                    result.push_back(result_line);
                    break;
                }
                
            }
        }

        return result;
        
    }
};


int main() {
    vector<string> v {"This", "is", "an", "example", "of", "text", "justification."};
    Solution s;

    auto result = s.fullJustify(v, 16);

    for(int q=0;q<result.size();q++) {
        cout << result[q] << endl;
    }

    return 0;
}