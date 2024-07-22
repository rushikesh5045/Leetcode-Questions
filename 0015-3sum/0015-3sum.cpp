class Solution {
public:
int speed= []{std::ios::sync_with_stdio(0);std::cin.tie(0);return 0;}();

    void twosum(vector<int>& nums,vector<vector<int>> &v,int one,int i)
    {
        int k=i+1;
        int n=nums.size()-1;
        while(k<n)
        {
                if(nums[k]+nums[n]+one==0)
                {
                    v.push_back({one,nums[k],nums[n]});
                    while(k<n&&nums[k]==nums[k+1])
                    {
                        k++;
                    }
                    while(n>k&&nums[n]==nums[n-1])
                    {
                        n--;
                    }
                    k++;n--;
                
                }else if(nums[k]+nums[n]+one>0)
                {
                    n--;
                }else{
                    k++;
                }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0||(i>0&&nums[i]!=nums[i-1]))
            {
                twosum(nums,v,nums[i],i);
            }
        }
        return v;

    }
};