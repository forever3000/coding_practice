class Solution {
public:
    bool isMatch(char a, char b)
    {
        if (a == '(' && b == ')')
        {
            return true;
        }
        else if (a == '{' && b == '}')
        {
            return true;
        }
        else if (a == '[' && b == ']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isValid(string s) {
        stack<char> S;
        
        if (s.size() == 0)
        {
            return true;
        }
        else
        {
            for (unsigned int i = 0; i < s.size(); i++)
            {
                if (S.empty())
                {
                    S.push(s[i]);
                }
                else
                {
                    if (!isMatch(S.top(), s[i]))
                    {
                        S.push(s[i]);
                    }
                    else
                    {
                        S.pop();
                    }
                }
            }
        }
        
        return (S.empty());
    }
};