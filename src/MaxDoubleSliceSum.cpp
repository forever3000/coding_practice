// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int K1[N] = {0};
    int K2[N] = {0};
    int max = 0;
    
    for (unsigned int i = 1; i < N - 1; i++)
    {
        K1[i] = std::max(K1[i - 1] + A.at(i), 0);
    }
    
    for (unsigned int i = N - 2; i > 0; i--)
    {
        K2[i] = std::max(K2[i + 1] + A.at(i), 0);    
    }
    
    for (unsigned int i = 1; i < N - 1; i++)
    {
        max = std::max(K1[i - 1] + K2[i + 1], max);    
    }
    
    return max;
}