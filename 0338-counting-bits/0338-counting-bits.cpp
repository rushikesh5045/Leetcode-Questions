class Solution {
public:
    int bits(int n)
    {
        int count=0;
        while(n>0)
        {
            if((n&1)==1)
            {
                count++;
            }
            n = n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(bits(i));
        }
        return ans;
    }
};
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();