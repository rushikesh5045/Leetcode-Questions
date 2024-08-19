class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<double>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                   double first = nums[i];
                   double second = nums[j];
                   double div =  first/second;
                if(q.size()<k)
                {
                   q.push({div,first,second});
                }else if(div<q.top()[0])
                {
                    q.pop();
                    q.push({div,first,second});
                }
            }
        }
    return {(int)q.top()[1],(int)q.top()[2]};
    }
};