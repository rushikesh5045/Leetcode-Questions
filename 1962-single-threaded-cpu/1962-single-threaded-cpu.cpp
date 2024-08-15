class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // makinga vector to store tasks + index
        vector<vector<int>> v;
        for (int i = 0; i < tasks.size(); i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        //sorting vector on basis of startTIme
        sort(v.begin(), v.end());


        long long currTime = 0;

        int idx =0;

        int n = v.size();

        // answer vector
        vector<int> ans;

        // priority queue (min heap) based on execution time and then based on index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        while (idx < n || !pq.empty()) {

            // if pq is empty and no process start at 0
            if(pq.empty()&&v[idx][0]>currTime)
            {
                currTime = v[idx][0];
            }

            // pushing all process which have same currTime
            while(idx<n&&v[idx][0]<=currTime)
            {
                pq.push({v[idx][1],v[idx][2]});
                idx++;
            }
            
            pair<int,int> p = pq.top();
            pq.pop();
            currTime+=p.first;
            ans.push_back(p.second);

        }
        return ans;
    }
};