class Solution {
public:

    // unordered_map<int, int> m;

    // int perfectSolution(int n) {
    //     if(n==0) return 0;
    //     if(n<0) return INT_MAX;

    //     if(m.find(n)!=m.end()) {
    //         return m[n];
    //     }
        
    //     int r = (int)sqrt(n);
        
    //     vector<int> results{INT_MAX};
        
    //     for(int i=1;i<=r;i++) {
    //         results.push_back(perfectSolution(n-(i*i))+1);
    //     }

    //     int min_num = results[0];
    //     for(int i=1;i<results.size();i++) {
    //         min_num = min_num > results[i] ? results[i] : min_num; 
    //     }
        
    //     m[n] = min_num;

    //     return min_num;
    // }
        
    int numSquares(int n) {
        if(n<=2) return n;

        vector<int> dp((n+1), INT_MAX);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++) {
            
            int r = (int)sqrt(n);
            for(int j=1;j<(r+1);j++) {
                int target = i-(j*j);
                if(target>=0) {
                    dp[i] = min(dp[i], dp[target]+1);
                } else break;
            }

        }

        return dp[n];
    }
};
