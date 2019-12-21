class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        int min = 999999;
        int sum = 0;
        
        // Handle edge cases
        if (N <= 3) {
            for (int i = 0; i < N; i++) {
                sum += nums.at(i);
            }
        }
        else {
            sort(nums.begin(), nums.end());
            
            for (int i = 0; i < N; i++)
            {
                int left = i + 1;
                int right = N - 1;
                
                while (left < right)
                {
                    if (abs((nums.at(i) + nums.at(left) + nums.at(right)) - target) < min) {
                        min = abs((nums.at(i) + nums.at(left) + nums.at(right)) - target);
                        sum = nums.at(i) + nums.at(left) + nums.at(right);
                    }
                    
                    if ((nums.at(left) + nums.at(right)) < (target - nums.at(i))) {
                        left += 1;
                    }
                    else if ((nums.at(left) + nums.at(right)) > (target - nums.at(i))) {
                        right -= 1;
                    }
                    else {
                        return (nums.at(i) + nums.at(left) + nums.at(right));
                    }
                }
            }
        }
        
        return sum;
    }
};
