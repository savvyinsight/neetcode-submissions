class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(word[0] == board[i][j] && dfs_stack(board,word,i,j)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs_stack(vector<vector<char>>& board, string word,int i,int j){
        // current coordinate, word index, current direction(0 down,1 up, 2 right, 3 left, 4 done)
        struct Frame{
            int x,y,idx,dir;
        };

        stack<Frame> st;
        board[i][j] = '#';
        st.push({i,j,0,0});

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!st.empty()){
            Frame &cur = st.top();

            if(cur.idx == word.size()-1) return true;
            
            if(cur.dir == 4){
                board[cur.x][cur.y] = word[cur.idx];
                st.pop();
                continue;
            }

            int nx = cur.x + dx[cur.dir];
            int ny = cur.y + dy[cur.dir];
            cur.dir++;

            if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size() && board[nx][ny] == word[cur.idx+1]){
                board[nx][ny] = '#';
                st.push({nx,ny,cur.idx+1,0});
            }

        }
        return false;
    }
};
