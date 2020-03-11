// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result(N, 0);
    int max = result.at(0);
    int base = 0;
    unsigned int i;
    
    if (A.empty())
    {
        return result;
    }
    
    for (i = 0; i < A.size(); i++)
    {
        if (A.at(i) == (N+1))
        {
            base = max;
        }
        else
        {
            if (A.at(i) <= result.size())
            {
                if (result.at(A.at(i) - 1) < base)
                    result.at(A.at(i) - 1) = base + 1;
                else
                    result.at(A.at(i) - 1)++;
                    
                if (max < result.at(A.at(i) - 1))
                {
                    max = result.at(A.at(i) - 1);   
                }
            }           
        }
    }
    
    for (i = 0; i < result.size(); i++)
    {
        if (result.at(i) < base)
        {
            result.at(i) = base;
        }
    }
    
    return result;
}