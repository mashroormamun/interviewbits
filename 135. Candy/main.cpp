class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1);

        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i-1] < ratings[i]) {
                res[i] = res[i-1] + 1;
            }
        }

        for(int i=ratings.size()-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                int num = res[i+1] + 1; 
                res[i] = max(res[i], num);
            }
        }

        int sum = 0;
        for(int i=0; i<ratings.size(); i++) {
            sum += res[i];
        }

        return sum;
    }
};
