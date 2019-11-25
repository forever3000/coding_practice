class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.size() == 0)
        {
            return ans;
        }
        else
        {
            sort (strs.begin(), strs.end());
            string a = strs.at(0);
            string b = strs.at(strs.size() - 1);
            
            for (unsigned int i = 0; i < a.size(); i++)
            {
                if (a[i] == b[i])
                {
                    ans += a[i];
                }
                else
                {
                    break;
                }
            }
        }
        
        return ans;
    }
};