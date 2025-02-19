class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[s.length()] = true;
        
        for(int i=s.length()-1;i>=0;i--) {
            int l = s.length()-i;
            
            for(int j=0;j<wordDict.size();j++) {
                if(l>=wordDict[j].length()) {
                    
                    
                    if(wordDict[j]==s.substr(i,wordDict[j].length())) {
                        if(dp[i+wordDict[j].length()] == true) {
                            dp[i]=true;
                            break;
                        }
                    }
                }
            }
        }
        
        // for(int i=0;i<dp.size();i++) {
        //     cout << i << " " << dp[i] << endl;
        // }
        
        return dp[0];
    }
};
