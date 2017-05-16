class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(board[i][j] == 'X' || board[i][j] == '*') return;
        board[i][j] = '*';
        if(i+1 < board.size())
            dfs(i+1,j,board);
        if(i-1 > 0)
            dfs(i-1,j,board);
        if(j+1 < board[0].size())
            dfs(i,j+1,board);
        if(j-1 > 0)
            dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        if( board.size() == 0) return;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1){
                    if(board[i][j] == 'O') dfs(i,j,board);
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '*') board[i][j] ='O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
};