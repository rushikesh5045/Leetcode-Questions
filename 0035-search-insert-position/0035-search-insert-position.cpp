class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int l=0,h=n;
         int mid = l + (h-l)/2;
        while(l<=h)
        {
            mid = l + (h-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }else if(nums[mid]>target)
            {
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        if(h<l)
        {
            return h+1;
        }else if(l>h)
        {
            return l;
        }
        return -1;
    }
};


// 1 2 3 5 6 7
// 0 1 2 3 4 5