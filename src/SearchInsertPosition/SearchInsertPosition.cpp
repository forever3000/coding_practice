class Solution {
public:
    int searchUpperIndex(vector<int>& nums, int left, int right, int target)
    {
        if (left >= right)
        {
            if (nums.at(left) < target)
                return left + 1;
            else
                return left;
        }
        else
        {
            int mid = (left + right) / 2;
            
            if (nums.at(mid) < target)
            {
                return searchUpperIndex(nums, mid + 1, right, target);
            }
            else if (nums.at(mid) > target)
            {
                return searchUpperIndex(nums, left, mid - 1, target);
            }
            else
            {
                return mid;
            }
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int index = searchUpperIndex(nums,  0, nums.size() -1, target);
        return index;
    }
};
