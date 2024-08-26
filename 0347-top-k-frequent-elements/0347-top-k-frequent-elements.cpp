class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto num:nums)
        {
            mp[num]++;
        }
        int n = nums.size()+1;
        vector<vector<int>> ans(n+1);
        vector<int>result;
        for(auto it:mp)
        {
            ans[it.second].push_back(it.first);
        }
        for(int i=ans.size()-1;i>0;i--)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                if(result.size()>=k)
                {
                    return result;
                }else{
                    result.push_back(ans[i][j]);
                }
            }
        }
        return result;
    }
};