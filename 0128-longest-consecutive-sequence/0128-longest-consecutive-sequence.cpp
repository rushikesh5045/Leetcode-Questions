// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) return 0;  
        
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int ans = 1;  
//         int count = 1;  

//         for (int i = 1; i < n; i++) {
//             if (nums[i] == nums[i - 1]) {
//                 continue;
//             }
//             if (nums[i] - nums[i - 1] == 1) {
//                 count++;
//             } else {
//                 ans = max(ans, count);  
//                 count = 1;  
//             }
//         }
//         ans = max(ans, count);  
//         return ans;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;

        for(auto n:nums)
        {
            if(s.find(n-1)==s.end())
            {
                int l = 1;
                while(s.find(n+l)!=s.end())
                {
                    l++;
                }
                ans = max(ans,l);
            }
        }
        return ans;
    }
};
