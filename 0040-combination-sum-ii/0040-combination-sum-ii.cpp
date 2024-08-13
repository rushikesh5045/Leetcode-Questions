class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int n, int i, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;

            if (nums[j] > target) break;
            
            temp.push_back(nums[j]);
            solve(nums, ans, temp, n, j + 1, target - nums[j]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums, ans, temp, n, 0, target);
        return ans;
    }
};
