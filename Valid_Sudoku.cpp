class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        // rows
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> mrow;
            for (int j = 0; j < 9; j++) {
                if (!check(board[i][j], mrow)) return false;
            }
        }
        
        // columns
        for (int j = 0; j < 9; j++) {
            unordered_map<char, int> mcol;
            for (int i = 0; i < 9; i++) {
                if (!check(board[i][j], mcol)) return false;
            }
        }
        
        // boxes
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 3; n++) {
                int istart = 3 * m, jstart = 3 * n;
                unordered_map<char, int> mbox;
                for (int i = istart; i < istart + 3; i++) {
                    for (int j = jstart; j < jstart + 3; j++) {
                        if (!check(board[i][j], mbox)) return false;
                    }
                }
            }
        }
        
        return true;
    }
    bool check(char b, unordered_map<char, int> &m) {
        if (b - '0' >= 1 && b - '0' <= 9) {
            if (m.find(b) != m.end()) return false;
            m[b] = 1;
        } else if (b != '.') return false;
        return true;
    }
};