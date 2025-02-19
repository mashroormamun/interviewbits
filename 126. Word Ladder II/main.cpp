class Solution {
public:
    bool isDifferByOneLetter(string &a, string &b) {
        int a_l = a.length();
        int b_l = b.length();
        
        int count = abs(a_l-b_l);
        if(count>1) return false;
        
        for(int i=0;i<min(a_l, b_l);i++) {
            if(a[i]!=b[i]) count++;
            
            if(count>1) return false;
        }
        
        return (count==1);
    }
    
    vector<vector<string>> result;
    int min_ans_len = INT_MAX;
    
    void findLaddersRec(string current, 
                        string target, 
                        vector<string> path, 
                        vector<bool> visited, 
                        vector<string>& wordList, 
                        int current_index) {
        path.push_back(current);
        
        if(current_index != -1) {
            visited[current_index]=true;
        }
        
        if(current == target) {
            if(path.size() < min_ans_len) {
                min_ans_len=path.size();
                result = vector<vector<string>>{path};
            } else if(path.size() == min_ans_len) {
                result.push_back(path);
            }
            
            return;
        }
        
        for(int i=0;i<wordList.size();i++) {
            if(visited[i]==false) {
                if(isDifferByOneLetter(current, wordList[i])) {
                    findLaddersRec(wordList[i], 
                                target, path, visited, wordList, i);
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        findLaddersRec(
            beginWord, 
            endWord, 
            vector<string> {}, 
            vector<bool> (wordList.size(), false), 
            wordList, 
            -1);
        
        return result;
    }
};
