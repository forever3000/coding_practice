// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int i;
    int j;
    int tmp;
    
    if (A.empty())
    {
        return A;
    }
    
    if (K == 0 || (K % A.size() == 0))
    {
        return A;
    }
    else
    {
        K = K % A.size();
    }
    
    for (i = 0; i < K; i++)
    {
        tmp = A.at(A.size() - 1);
        
        for (j = A.size() - 1; j >= 0; j--)
        {
            if (j == 0)
            {
                A.at(j) = tmp;
            }
            else
            {
                A.at(j) = A.at(j - 1);
            }
        }
    }
    
    return A;
}