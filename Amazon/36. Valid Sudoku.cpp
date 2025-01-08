class Solution {
public:
    bool traversal(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        set<char> st;
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if (board[i][j] == '.') continue;
                if (st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Checking rows
        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }

        // Checking columns
        for (int j = 0; j < 9; j++) {
            set<char> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }

        // Checking the 3x3 boxes
        for (int sr = 0; sr < 9; sr += 3) {
            for (int sc = 0; sc < 9; sc += 3) {
                if (!traversal(board, sr, sr + 2, sc, sc + 2)) return false;
            }
        }

        return true;
    }
};