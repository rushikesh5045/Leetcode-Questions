class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) return true;  // Array is already sorted

        // Check if the array is sorted from pivot to the end
        for (int i = pivot; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        // Check if the array is sorted circularly
        if (nums[nums.size() - 1] > nums[0]) {
            return false;
        }

        return true;
    }
};
