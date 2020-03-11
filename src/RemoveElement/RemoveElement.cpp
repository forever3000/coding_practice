class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unsigned int index = 0;
        unsigned int length = 0;
        
        for (unsigned int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) == val)
            {              
            }
            else
            {
                nums.at(index) = nums.at(i);
                index ++;
                length ++;
            }
        }
        
        return length;
    }
};