class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;  
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;  
        int count = 1;  

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] - nums[i - 1] == 1) {
                count++;
            } else {
                ans = max(ans, count);  
                count = 1;  
            }
        }
        ans = max(ans, count);  
        return ans;
    }
};
