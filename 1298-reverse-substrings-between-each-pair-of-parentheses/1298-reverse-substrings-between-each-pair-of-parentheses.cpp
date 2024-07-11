class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>q;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=')')
            {
                q.push(s[i]);
            }else{
                string str;
                     while(q.top()!='(')
                {
                    str+=q.top();
                    q.pop();
                }
                q.pop();
                for(int i=0;i<str.size();i++)
                {
                    q.push(str[i]);
                }
               
            }
        }
        string ans;
        while(!q.empty())
        {
            ans+=q.top();
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        // string result;
        // for(int i=0;i<ans.size();i++)
        // {
        //     if(ans[i]!=')'&&ans[i]!='(')
        //     {
        //         result+=ans[i];
        //     }
        // }
        // return result;
        return ans;
    }
};