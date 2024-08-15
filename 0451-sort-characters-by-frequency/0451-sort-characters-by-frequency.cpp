class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        s="";
        while(!pq.empty())
        {
            int a = pq.top().first;
            for(int i=0;i<a;i++)
            {
                s+=pq.top().second;
            }
            pq.pop();
        }
        return s;
    }
};