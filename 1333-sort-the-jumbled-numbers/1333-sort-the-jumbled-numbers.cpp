class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<string> st;
        for(auto i:nums)
        {
            st.push_back(to_string(i));
        }
        for(int i=0;i<st.size();i++)
        {
            int size = st[i].size();
            for(int j=0;j<size;j++)
            {
                int a = st[i][j]-'0';
                int b = mapping[a];
                st[i][j]=b+'0';
            }
        }
        vector<int> vec;
        for(int i=0;i<st.size();i++)
        {
            vec.push_back(stoi(st[i]));
        }
        vector<pair<int,int>> temp;
        for(int i=0;i<vec.size();i++)
        {
            temp.push_back({vec[i],nums[i]});
        }
        auto my =[](pair<int,int>p1,pair<int,int>p2){
            return p1.first<p2.first;
        };
        sort(temp.begin(),temp.end(),my);
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=temp[i].second;
        }
        return nums;
    }
};