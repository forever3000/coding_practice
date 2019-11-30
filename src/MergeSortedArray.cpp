class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (unsigned int i = 0; i < n; i++)
        {
            nums1.at(m + i) = nums2.at(i);
        }
        sort(nums1.begin(), nums1.end());
    }
};
