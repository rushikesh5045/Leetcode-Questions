class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        double ans = INT_MIN;
        double sum = 0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
            ans = max(ans,sum/k);
        for(int i=1;i<=nums.size()-k;i++)
        {
            sum-=nums[i-1];
            sum+=nums[i+k-1];
            ans = max(ans,sum/k);
        }
        return ans;
    }
};