class Solution {
    int n;
public:
    int solve(int curr,int past)
    {
        if(curr==n) return 0;
        if(curr>n) return 1000;

        int cp = 2 + solve(2*curr,curr);
        int p = 1 + solve(curr+past,past);
        return min(cp,p);
    }
    int minSteps(int n) {
        if(n==1)
        {return 0;}
        this->n=n;
        return 1+solve(1,1);
    }
};