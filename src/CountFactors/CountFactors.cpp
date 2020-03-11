// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int count = 0;
    unsigned int i = 0;
    
    if (N < 0)
    {
        return 0;
    }
    else if (N == 1)
    {
        return 1;
    }
    else
    {
        for (i = 2; i * i < N; i++)
        {
            if (N % i == 0)
            {
                count += 2;
            }
        }
        
        if (i * i == N)
        {
            count += 1;
        }
        
        count += 2;
    }
    
    return count;
}