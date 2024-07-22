/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let i =0;
    let j =nums.length-1;
    let temp = [...nums];
    let a=0;
    let b=0;
    let ans = [-1,-1];
    temp.sort((n,m)=>n-m);

    while(i<j)
    {
        if(temp[i]+temp[j]==target)
        {
            a=temp[i];
            b=temp[j];
            break;
        }else if(temp[i]+temp[j]>target)
        {
            j--;
        }else{
            i++;
        }
    }

console.log(a);
console.log(b);
    for(let k=0;k<nums.length;k++)
    {
        if(nums[k]==a)
        {
            ans[0]=k;

        }
      
    }

    for(let h=0;h<nums.length;h++)
    {
          if(nums[h]==b && h!=ans[0])
        {
            ans[1]=h;
        }
    }
    return ans;

};