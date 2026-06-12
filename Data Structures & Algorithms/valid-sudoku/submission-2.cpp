class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //use boolean arrays instead of sets for better performance
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for(int i = 0;i<9;++i){
            for(int j = 0;j<9;++j){
                //skip empty cells
                if(board[i][j] == '.') continue;

                //convert to index 0-8
                int index = board[i][j] - '1';
                int boxIndex = (i/3)*3 + j/3;

                //If already seen in box,row, or col
                if(row[i][index] || col[j][index] || box[boxIndex][index]){
                    return false;
                }

                //Mark as seen
                row[i][index] = true;
                col[j][index] = true;
                box[boxIndex][index] = true;
            }
        }
        return true;
    }
};
