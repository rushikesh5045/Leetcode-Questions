class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five=0,ten=0,twenty=0;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                five+=1;
                continue;
            }else if(bills[i]==10)
            {
                ten+=1;
                if(five<1)
                {
                    return false;
                }else{
                    five-=1;
                    continue;
                }
            }else{
                twenty+=1;
                bool isPossiblewithfive = five>=3 ;
                bool isPossiblewithtenandfive = ten>=1 && five>=1 ;
                
                    if(isPossiblewithfive==false && isPossiblewithtenandfive==false)
                    {
                        return false;
                    }
                if(isPossiblewithtenandfive)
                {
                    ten-=1;
                    five-=1;
                    continue;
                }else if(isPossiblewithfive){
                    five-=3;
                    continue;
                }
            }
        }
    return true;
    }
};