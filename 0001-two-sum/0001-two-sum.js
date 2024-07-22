/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let i =0;
    let j =nums.length-1;
    let temp = nums.map((num,index)=>[num,index]);
    let ans = [-1,-1];
    temp.sort((n,m)=>n[0]-m[0]);

    while(i<j)
    {
        if(temp[i][0]+temp[j][0]==target)
        {
            ans[0]=temp[i][1];
            ans[1]=temp[j][1];
            break;
        }else if(temp[i][0]+temp[j][0]>target)
        {
            j--;
        }else{
            i++;
        }
    }
return ans;

};