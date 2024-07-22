class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a = nums;
        vector<int> ans (2,-1);
        sort(a.begin(),a.end());
        int p1 = 0;
        int p2=nums.size()-1;
        while(p1<p2)
        {
            if(a[p1]+a[p2]==target)
            {
                ans = {a[p1],a[p2]};
                break;
            }else if(a[p1]+a[p2]<target)
            {
                p1++;
            }else{
                p2--;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a[p1])
            {
                ans[0]=i;
                break;
            }
        }
          for(int i=0;i<nums.size();i++)
        {
            if((nums[i]==a[p2])&&i!=ans[0])
            {
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};