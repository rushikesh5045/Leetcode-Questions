class Solution {
public:
    bool check(int a,int b)
    {
        if(a==b)
        {
            return true;
        }
        string str = to_string(a);
        int n = str.size()-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                swap(str[i],str[j]);
                if(stoi(str)==b)
                {
                    return true;
                }
                swap(str[i],str[j]);
            }
        }
        string str2 = to_string(b);
         n = str2.size()-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                swap(str2[i],str2[j]);
                if(stoi(str2)==a)
                {
                    return true;
                }
                swap(str2[i],str2[j]);
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j&&i<j)
                {
                   if( check(nums[i],nums[j]))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};