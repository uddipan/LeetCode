class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int x, int y)
    {
        if(word.empty())return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[0])
        {
            return false;
        }
        char c = board[x][y];
        board[x][y] = NULL;
        string tmp(word.substr(1));
        if(helper(board,tmp,x-1,y) || helper(board,tmp,x+1,y) || helper(board,tmp,x,y-1) || helper(board,tmp,x,y+1))
        {
            return true;
        }
        board[x][y] = c;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(helper(board,word,i,j))return true;
            }
        }
        return false;
    }
};