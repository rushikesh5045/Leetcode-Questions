class Solution {
public:
#define P pair<int,int>
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        vector<P> ans;
        for(auto vec:edges)
        {
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]}); 
        }
        for(int i=0;i<n;i++)
        {
            priority_queue<P,vector<P>,greater<P>>pq;
            vector<int> dist(n,INT_MAX);
            dist[i]=0;
            pq.push({0,i});
            while(!pq.empty())
            {
                int node = pq.top().second;
                int distance = pq.top().first;
                pq.pop();
                // if (distance > dist[node]) continue;
                for(auto v:adj[node])
                {
                    int d = v.second;
                    int n = v.first;
                    if((distance+d<=distanceThreshold)&&(distance+d<dist[n]))
                    {
                        dist[n] = distance+d;
                        pq.push({distance+d,n});
                    } 
                }
            }
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(dist[i]<=distanceThreshold)
                {
                    count++;
                }
            }
            ans.push_back({count,i});
        }
        auto my = [](P p1,P p2){
            if(p1.first==p2.first)
            {
                return p1.second>p2.second;
            }
            return p1.first<p2.first;
        };
        sort(ans.begin(),ans.end(),my);
        return ans[0].second;
    }
};