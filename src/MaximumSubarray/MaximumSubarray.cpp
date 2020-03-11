class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int N = nums.size();
        int abs_max = INT_MIN;
        
        for (int i = 0; i < N; i++)
        {
            if ((curr_sum + nums.at(i)) < nums.at(i))
            {
                curr_sum = nums.at(i);
            }
            else
            {
                curr_sum += nums.at(i);
            }
            
            if (abs_max < curr_sum)
            {
                abs_max = curr_sum;
            }
        }
        
        return abs_max;
    }
};
