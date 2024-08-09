class Solution {
public:
    bool isMagic(vector<vector<int>>& grid,int i,int j)
    {
        bool seen[10]={false};
        for(int a=0;a<3;a++)
        {
            for(int b=0;b<3;b++)
            {
                int num = grid[i+a][j+b];
                if(num<1||num>9)
                {
                    return false;
                }
                if(seen[num])
                {
                    return false;
                }
                seen[num]=true;
            }
        }
        int d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int d2 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
        if(d1!=d2)
        {
            return false;
        }
        int r1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        if(r1!=d1) return false;
        int r2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
        if(r2!=d1) return false;
        int r3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
        if(r3!=d1) return false;

        int c1 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
        if(c1!=d1) return false;
        int c2 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
        if(c2!=d1) return false;
        int c3 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
        if(c3!=d1) return false;

        return true;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        if(m<3||n<3)
        {
            return 0;
        }
        for(int i=0;i<m-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                if(isMagic(grid,i,j))
                {
                    ans++;
                }
            }
        }
    return ans;
    }
};