class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums ):k(k) {
     for(int i=0;i<nums.size();i++)
     {
        if(q.size()<k)
        {
            q.push(nums[i]);
        }else if(nums[i]>q.top())
        {
            q.pop();
            q.push(nums[i]);
        }
     }

     while(q.size()<k)
     {
        q.push(INT_MIN);
     }
    }
    
    int add(int val) {
        if(q.size()<k)
        {
            q.push(val);
        }
        else if(val>q.top())
        {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */