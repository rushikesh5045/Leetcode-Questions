class Solution {
public:
    bool check(vector<vector<int>>&adj,int curr,vector<int>&color,int currColor)
    {
        color[curr]=currColor;
        for(auto vec:adj[curr])
        {
            if(color[vec]==currColor)
            {
                return false;
            }
            if(color[vec]==-1)
            {
                color[vec]=1-currColor;
                if(check(adj,vec,color,color[vec])==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto vec:dislikes)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i+1]==-1)
            {
                if((check(adj,i+1,color,1)==false))
                {
                return false;
                }
            }
        }
        return true;
    }
};