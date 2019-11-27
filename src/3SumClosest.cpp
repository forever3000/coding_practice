class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        unsigned int N = nums.size();
        unsigned int left;
        unsigned int right;
        unsigned int i_pos = 0;
        unsigned int i_neg = 0;
        int sum_pos = 0;
        int sum_neg = 0;
        int min_pos = 10000;
        int min_neg = -10000;
        int diff;
        
        if (N == 0)
        {
            return 0;
        }
        else if (N <= 3)
        {
            int sum = 0;
            for (unsigned int i = 0; i < N; i++)
            {
                sum += nums.at(i);
            }
            return sum;
        }
        else
        {
            sort(nums.begin(), nums.end());
            
            for (unsigned int i = 0; i < N - 2; i++)
            {
                int complement = target - nums.at(i);
                left = i + 1;
                right = N-1;
                
                while (left < right)
                {
                    diff = nums.at(left) + nums.at(right) - complement;
                    
                    if (diff > 0 && diff < min_pos)
                    {
                        min_pos = diff;
                        i_pos = i;
                        sum_pos = diff + complement;
                        right --;
                    }
                    else if (diff < 0 && diff > min_neg)
                    {
                        min_neg = diff;
                        i_neg = i;
                        sum_neg = diff + complement;
                        left ++;
                    }
                    else if (diff == 0)
                    {
                        i_pos = i;
                        i_neg = i;
                        i = N;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (abs(min_pos) < abs(min_neg))
        {
            cout << "pos : " << i_pos << "," << sum_pos << endl;
            return sum_pos + nums.at(i_pos);
        }
        else
        {
            cout << "neg : " << i_neg << "," << sum_neg << endl;
            return sum_neg + nums.at(i_neg);
        }
    }
};
