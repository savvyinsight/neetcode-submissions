class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //use arrays of sets to track seen number
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i = 0;i<9;++i){
            for(int j = 0;j<9; ++j){
                char ch = board[i][j];
                //skip empty cells
                if(ch == '.') continue;

                //check row
                if(row[i].count(ch)) return false;
                row[i].insert(ch);

                //check column
                if(col[j].count(ch)) return false;
                col[j].insert(ch);

                //check box - calculate box index
                int boxIndex = (i/3)*3 + j/3;
                if(box[boxIndex].count(ch)) return false;
                box[boxIndex].insert(ch);
            }
        }
        return true;
    }
};
