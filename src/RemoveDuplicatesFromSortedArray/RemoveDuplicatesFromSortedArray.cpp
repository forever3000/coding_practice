class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unsigned int index = 0;
        unsigned int N = nums.size();
        
        if (N == 0)
        {
            return 0;
        }
        else
        {
            int prev_value = nums.at(0);
            index ++;
            for (unsigned int i = 1; i < N; i++)
            {
                if (nums.at(i) == prev_value)
                {
                    
                }
                else
                {
                    nums.at(index) = nums.at(i);
                    prev_value = nums.at(i);
                    index ++;
                }
            }
        }
        return index;
    }
};
