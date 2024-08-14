class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i,int j,int index,int m,int n)
    {
        if(index==word.size())
        {
            return true;
        }
        if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[index])
        {
            return false;
        }

        char t = board[i][j];
        board[i][j]='@';
        bool found = solve(board,word,i+1,j,index+1,m,n)||solve(board,word,i,j-1,index+1,m,n)||solve(board,word,i-1,j,index+1,m,n)||solve(board,word,i,j+1,index+1,m,n);
        board[i][j]=t;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(board,word,i,j,0,m,n))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};