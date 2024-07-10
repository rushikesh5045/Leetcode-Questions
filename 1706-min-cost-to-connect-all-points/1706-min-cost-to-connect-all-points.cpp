class Solution {
public:
    int spanningTree(int V, vector<vector<pair<int,int>>>&adj)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        vector<bool>inMST(V);
        que.push({0,0});
        int sum=0;
        while(!que.empty())
        {
            pair<int,int> temp = que.top();
            que.pop();
            if(inMST[temp.second]) continue;
            inMST[temp.second]=true;
            sum+=temp.first;
            for(auto &vec:adj[temp.second])
            {
                if(inMST[vec.first]==false)
                {
                    que.push({vec.second,vec.first});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>>adj(points.size());
        for(int i=0;i<points.size();i++)
        {
           for(int j=0;j<points.size();j++)
           {
            if(i!=j)
            {
                adj[i].push_back({j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
           }
        }
    return spanningTree(points.size(),adj);
    }
};