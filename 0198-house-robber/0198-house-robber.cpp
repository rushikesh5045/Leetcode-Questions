/*

// recursive approach

class Solution {
public:
    int solve(int i,vector<int>& nums)
    {
        int n = nums.size();
        if(i>=n)
        {
            return 0;
        }
        int steal = nums[i]+solve(i+2,nums);
        int skip = solve(i+1,nums);
        return max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int i=0;
        return solve(i,nums);
    }
};

*/



// memoization (top-bottom)
class Solution {
public:
    int dp[101];
    int solve(int i,vector<int>& nums)
    {
        int n = nums.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int steal = nums[i]+solve(i+2,nums);
        int skip = solve(i+1,nums);
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int i=0;
        memset(dp,-1,sizeof(dp));
        return solve(i,nums);
    }
};