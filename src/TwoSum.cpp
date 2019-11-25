class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned int N = nums.size();
        map<int, unsigned int> M;
        
        if (N < 2)
        {
            return vector<int> {0, 0};
        }
        else
        {
            for (unsigned int i = 0; i < N; i++)
            {
                int compensation = target - nums.at(i);
                auto it = M.find(compensation);
                
                if (it != M.end())
                {
                    return vector<int> {it->second, i};
                }
                else
                {
                    M.insert(pair<int, unsigned int>(nums.at(i), i));
                }
            }
            return vector<int> {0, 0};
        }          
    }
};