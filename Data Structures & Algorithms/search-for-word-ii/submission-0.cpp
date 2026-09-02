class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        string word;
        TrieNode():word(""){
            for(int i = 0;i<26;i++) children[i] = nullptr;
        }
    };

    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();

        for(string& w:words){
            TrieNode* cur = root;
            for(char& c:w){
                if(!cur->children[c-'a']) cur->children[c-'a'] = new TrieNode();
                cur = cur->children[c-'a'];
            }
            cur->word = w;
        }
        return root;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;

        TrieNode* root = buildTrie(words);
        int n = board.size(),m = board[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                dfs(board,i,j,res,root);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board,int i,int j,vector<string>& res,TrieNode* root){
        char c = board[i][j];
        if(c=='#' || !root->children[c-'a']) return;

        TrieNode* cur = root->children[c-'a'];
        if(!cur->word.empty()){
            res.push_back(cur->word);
            cur->word = "";
        }

        board[i][j] = '#';

        int dirs[5] = {1,0,-1,0,1};
        for(int d = 0;d<4;d++){
            int ni = i+dirs[d];
            int nj = j+dirs[d+1];
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size()){
                dfs(board,ni,nj,res,cur);
            }
        }

        board[i][j] = c;
    }
};
