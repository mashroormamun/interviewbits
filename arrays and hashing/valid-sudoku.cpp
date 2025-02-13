class Solution {
public:
bool isColumnValid(vector<vector<char>>& board, int col) {
    set<char> s;

    for(int i=0;i<9;i++) {
        char c = board[i][col];
        if (c != '.') {
            auto ins = s.insert(c);
            if (ins.second == false)
                return false;
        }
    }

    return true;
}

bool isRowValid(vector<vector<char>>& board, int row) {
    set<char> s;

    for(int i=0;i<9;i++) {
        char c = board[row][i];
        if (c != '.') {
            auto ins = s.insert(c);
            if (ins.second == false)
                return false;
        }
    }

    return true;
}

bool isBlockValid(vector<vector<char>>& board, int row, int col) {
    set<char> s;

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            char c = board[i+row][j+col];
            if (c != '.') {
                auto ins = s.insert(c);
                if (ins.second == false)
                    return false;
            }
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0;i<9;i++) {
        bool isValid = isColumnValid(board, i);
        if (isValid == false)
            return false;
        
        isValid = isRowValid(board, i);
        if (isValid == false)
            return false;
    }

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            bool isValid = isBlockValid(board, i*3, j*3);
            if (isValid == false)
                return false;
        }
    }

    return true;
}
};

