class Solution {
public:
    void twoSum(vector<int>& nums,int n1,int index,int n,vector<vector<int>>&ans)
    {
        int start = index;
        int end = n;
        while(start<end)
        {
            if(nums[start]+nums[end]>n1)
            {
                end--;
            }else if(nums[start]+nums[end]<n1)
            {
                start++;
            }else{
                ans.push_back({-n1,nums[start],nums[end]});
                while(start<end&&nums[start]==nums[start+1]) start++;
                while(start<end&&nums[end]==nums[end-1]) end--;
                start++;
                end--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int n1 = -nums[i];
            twoSum(nums,n1,i+1,n-1,ans);
        }
        return ans;
    }
};