class Solution {
public:
    //0 : dead-dead, 1:dead-live, 2:live-dead, 3:live-live
    void livenbr(int i,int j, vector<vector<int>>& board)
    {
        int cnt = 0;
        for(int u=i-1; u<=i+1; u++)
        {
            for(int v=j-1; v<=j+1; v++)
            {
                if(u < 0 || u >= board.size())continue;
                if(v < 0 || v >= board[0].size())continue;
                if(board[u][v] > 1)cnt++;
            }
        }
        
        if(board[i][j] == 3)
        {
            cnt--;
            if(cnt < 2)board[i][j] = 2;
            else if(cnt <4)board[i][j] = 3;
            else board[i][j] = 2;
        }
        else
        {
            if(cnt == 3)board[i][j] = 1;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j])board[i][j] = 3;
            }
        }
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                livenbr(i,j,board);
            }
        }
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]%2)board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
        
    }
};