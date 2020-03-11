class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        // edge-case, return an empty vector if nums is empty
        if (nums.empty()) return res;
        
        int len = nums.size();
        
        // sort numbers, n log n
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < len; i++) {
            // if nums[i] is larger than zero, we're out of potential combinations
            if (nums[i] > 0) return res;

            // skip if we already processed this number
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            
            // now that one of the numbers is fixed (nums[i])
            // we can find matches using a sliding window
            int left = i + 1;
            int right = len - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    // we've got a match
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // to avoid duplicates, we need to skip numbers
                    // we already processed
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++, right--;
                }
            }
        }
        
        return res;
    }
};