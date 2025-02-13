class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> res(numRows, "");
        bool countDown = true;
        int rowNum = 0;

        for(int i=0; i<s.size(); i++) {
            res[rowNum] += s[i];

            if(rowNum == numRows-1) countDown = false;
            if(rowNum == 0) countDown = true;

            if(countDown) rowNum++;
            if(!countDown) rowNum--;
        }
        
        string result = "";
        for (int i=0; i<numRows; i++)
            result += res[i];

        return result;
    }
};
