class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>=65&&s[i]<=90))
            {
                s[i]= s[i]-'A'+'a';
                ans+=s[i];
            }else if(s[i]>=97&&s[i]<=122){
               ans+=s[i];
            }else if(s[i]>=48&&s[i]<=57)
            {
                ans+=s[i];
            }
            else{
                continue;
            }
        }
       string t = ans;
       reverse(t.begin(),t.end());
       return ans==t;
    }
};