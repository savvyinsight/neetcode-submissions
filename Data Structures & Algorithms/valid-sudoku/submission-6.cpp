class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            unordered_set<char> seen;
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }

        for(int i = 0;i<9;i++){
            unordered_set<char> seen;
            for(int j = 0;j<9;j++){
                char val = board[j][i];
                if(val == '.') continue;
                if(seen.count(val)) return false;
                seen.insert(val);
            }
        }

        for(int r = 0;r<9;r++){
            unordered_set<char> seen;
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    int row = (r/3)*3 + i;
                    int col = (r%3)*3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
