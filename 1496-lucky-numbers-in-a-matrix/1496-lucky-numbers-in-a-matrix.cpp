class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> mininrow;
        set<int> maxincolumn;
        for(int i=0;i<m;i++)
        {
            int mini = INT_MAX;
              for(int j=0;j<n;j++)
            {
                mini=min(mini,matrix[i][j]);
            }
            mininrow.insert(mini);
        }
         for(int i=0;i<n;i++)
        {
            int maxi = INT_MIN;
              for(int j=0;j<m;j++)
            {
                maxi=max(maxi,matrix[j][i]);
            }
            maxincolumn.insert(maxi);
        }
        for(auto t:mininrow)
        {
            if(maxincolumn.find(t)!=maxincolumn.end())
            {
                ans.push_back(t);
            }
        }
    return ans;
    }
};

/*

[3,7,8]
[9,11,13]
[15,16,17]



*/