class Solution {
public:
    int n, m;
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') infect(board, 0, j);
            if (board[n-1][j] == 'O') infect(board, n-1, j);
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') infect(board, i, 0);
            if (board[i][m-1] == 'O') infect(board, i, m-1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
    void infect(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'A';
        if (i+1 < n) infect(board, i+1, j);
        if (i-1 >= 0) infect(board, i-1, j);
        if (j+1 < n) infect(board, i, j+1);
        if (j-1 >= 0) infect(board, i, j-1);
    }
};