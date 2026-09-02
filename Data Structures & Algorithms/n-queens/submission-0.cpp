class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n,false);
        vector<bool> diag1(n,false);
        vector<bool> diag2(n,false);

        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));

        dfs(res,board,col,diag1,diag2,n,0);

        return res;
    }

    void dfs(vector<vector<string>>& res,vector<string>& board,vector<bool>& col,vector<bool>& diag1,vector<bool>& diag2,int n,int row){
        if(row == n){
            res.push_back(board);
            return;
        } 

        for(int c = 0;c<n;c++){
            int d1 = row-c+n-1;
            int d2 = row+c;

            if(col[c] || diag1[d1] || diag2[d2]) continue;
            board[row][c] = 'Q';
            col[c] = diag1[d1] = diag2[d2] = true;

            dfs(res,board,col,diag1,diag2,n,row+1);

            board[row][c] = '.';
            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }
};
