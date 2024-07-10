class Solution {
public:
#define P pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijkstra's shortest path algo
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int>result(n,INT_MAX);
        result[k-1]=0;
        pq.push({0,k});
        unordered_map<int,vector<P>> adj;
        for(auto tp:times)
        {
            adj[tp[0]].push_back({tp[1],tp[2]});
        }
        while(!pq.empty())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto &v:adj[node])
            {
                int n = v.first;
                int t = v.second;
                if(t+time<result[n-1])
                {
                    result[n-1]=t+time;
                    pq.push({t+time,n});
                }
            }
        }
        int answer=INT_MIN;
    for(int i=0;i<result.size();i++)
    {
        answer=max(answer,result[i]);
    }
    return answer==INT_MAX?-1:answer;
    }
};