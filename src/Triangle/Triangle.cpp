// you can use includes, for example:
// #include <algorithm>

#include <bits/stdc++.h> 
using namespace std; 

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int i;
    
    if (A.size() < 3)
    {
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    for (i = 0; i < A.size() - 2; i++)
    {
        if (A.at(i) > 0 && A.at(i) > (A.at(i + 2) - A.at(i + 1)))
        {
            return 1;
        }
    }
    
    return 0;
}