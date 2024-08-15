class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto pile:piles)
        {
            pq.push(pile);
        }
        for(int i=0;i<k;i++)
        {
            int a = pq.top();
            pq.pop();
            a -= floor(a/2);
            pq.push(a);
        }

        int a =0;

        while(!pq.empty())
        {
            a+=pq.top();
            pq.pop();
        }
        return a;
    }
};