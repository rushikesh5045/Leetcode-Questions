class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;
        int n = names.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({heights[i],names[i]});
        }
        auto my=[](pair<int,string>p1,pair<int,string>p2){
            return p1.first>p2.first;
        };
        sort(v.begin(),v.end(),my);
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};