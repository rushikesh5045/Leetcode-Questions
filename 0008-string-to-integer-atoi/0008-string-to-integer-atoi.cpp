class Solution {
public:
    int myAtoi(string s) {
        //removing leading whitespaces;
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        s=s.substr(i);

        // checking for sign


        bool isPositive=true;
        bool isChecked=false;
        long long h = 2147483648;
        if(s[0]=='+')
        {
            isPositive=true;
            isChecked=true;
            s = s.substr(1);
        }else if(s[0]=='-')
        {
            isChecked=true;
            isPositive=false;
            s=s.substr(1);
        }
        //getting the number
        int j=0;
        long long a=0;
        while(s[j]-'0'>=0&&s[j]-'0'<=9&&j<s.size())
        {
            int temp = s[j]-'0';
            if(isPositive==true && a*10+temp >=(INT_MAX))
            {
                return INT_MAX;
            }else if(isPositive==false && a*10+temp == INT_MAX)
            {
                return INT_MIN+1;
            }else if(isPositive==false && a*10+temp >= h)
            {   
             return INT_MIN;
            }
            else{
            a = a*10 + temp;
            j++;
            }
        }
        if(isPositive==false&&isChecked==true)
        {
            a = -a;
        }
        return a;
    }
};