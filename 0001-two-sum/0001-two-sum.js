/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
       let ans = [-1,-1];
    let n=nums.length;
    for(let i=0;i<n;i++)
    {
        let a = nums[i];
        for(let j=i+1;j<n;j++)
        {
            if(nums[j]==target-a)
            {
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }

};