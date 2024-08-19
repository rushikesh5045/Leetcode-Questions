class Solution {
public:
    int minSetSize(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        int reqSize = nums.size()/2;
        int currSize = 0;
        int ans = 0;
        while(currSize<reqSize)
        {
            ans+=1;
            currSize+=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};