class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>t(n+1);
        t[1]=1;
        int i2=1,i3=1,i5=1;
        for(int i=2;i<=n;i++)
        {
            int a = t[i2]*2;
            int b = t[i3]*3;
            int c = t[i5]*5;

            int mini = min({a,b,c});
            t[i]=mini;
            if(mini==a)
            {
                i2++;
            }
            if(mini==b)
            {
                i3++;
            }
            if(mini==c)
            {
                i5++;
            }
        }
        return t[n];
    }
};