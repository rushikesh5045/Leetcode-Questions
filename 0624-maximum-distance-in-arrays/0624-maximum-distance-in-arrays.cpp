class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {

        int maxi = INT_MIN;
        int mini = INT_MAX;
        int minIndex = -1;
        int maxIndex = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i].back();  // Last element in the subarray
            int b = nums[i].front(); // First element in the subarray
            
            // Update maxi and maxIndex
            if (a > maxi) {
                maxi = a;
                maxIndex = i;
            }
            
            // Update mini and minIndex
            if (b < mini) {
                mini = b;
                minIndex = i;
            }
        }
        
        // If the max and min are from the same subarray, we need to consider alternatives
        if (minIndex == maxIndex) {
            // Find second maximum and second minimum
            int secondMaxi = INT_MIN;
            int secondMini = INT_MAX;
            
            for (int i = 0; i < nums.size(); i++) {
                if (i != maxIndex) {
                    secondMaxi = max(secondMaxi, nums[i].back());
                    secondMini = min(secondMini, nums[i].front());
                }
            }
            // Return the maximum of the two possible distances
            return max(maxi - secondMini, secondMaxi - mini);
        }

        return maxi - mini;
    }
};
