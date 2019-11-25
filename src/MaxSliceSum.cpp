// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int next_sum;
    int local_max;
    int absolute_max;
    
    if (A.size() == 0)
    {
        return 0;
    }
    else if (A.size() == 1)
    {
        return A.at(0);
    }
    else
    {
        next_sum = A.at(0);
        local_max = A.at(0);
        absolute_max = A.at(0);
        for (unsigned int i = 1; i < A.size(); i++)
        {
            next_sum = local_max + A.at(i);
            local_max = std::max(next_sum, A.at(i));
            absolute_max = std::max(absolute_max, local_max);
        }
        
        return absolute_max;
    }
}