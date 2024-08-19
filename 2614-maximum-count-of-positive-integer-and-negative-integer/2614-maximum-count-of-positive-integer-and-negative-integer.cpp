class Solution {
public:
    int search(vector<int>& nums,int l,int e, double target)
    {
        int mid=0;
        while(l<=e)
        {
            mid = (l+e)/2;
          if((double)nums[mid]<target)
            {
                l=mid+1;
            }else{
                e=mid-1;
            }
        }
        return l;
    }
    int maximumCount(vector<int>& nums) {
        int neg = search(nums,0,nums.size()-1,-0.5);
        int pos = search(nums,0,nums.size()-1,0.5);
        int diff = nums.size()-pos;

        return max(neg,diff);
    }
};