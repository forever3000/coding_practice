class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        char previous = 0;
        
        for (unsigned int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'M')
            {
                result += 1000;
                if (previous == 'C')
                {
                    result -= 200;
                }
            }
            else if (s[i] == 'D')
            {
                result += 500;
                if (previous == 'C')
                {
                    result -= 200;
                }
            }
            else if (s[i] == 'C')
            {
                result += 100;
                if (previous == 'X')
                {
                    result -= 20;
                }                
            }
            else if (s[i] == 'L')
            {
                result += 50;
                if (previous == 'X')
                {
                    result -= 20;
                }
            }
            else if (s[i] == 'X')
            {
                result += 10;
                if (previous == 'I')
                {
                    result -= 2;
                }
            }
            else if (s[i] == 'V')
            {
                result += 5;
                if (previous == 'I')
                {
                    result -= 2;
                }
            }
            else if (s[i] == 'I')
            {
                result += 1;
            }
            
            previous = s[i];
        }
        
        return result;
    }
};