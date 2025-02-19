class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> result;
        unordered_map<int, int> m;

        for(int i=0;i<paint.size();i++) {
            int start = paint[i][0];
            int end   = paint[i][1];
            int work  = 0;

            while(start<end) {
                if(m.find(start) != m.end()) {
                    // update start
                    int prev_start = m[start];
                    m[start]       = max(end, m[start]);
                    start          = prev_start;
                    
                } else {
                    // update work 
                    work++;
                    m[start] = end;
                    start++;
                }
            }

            result.push_back(work);
        }

        return result;
    }
};
