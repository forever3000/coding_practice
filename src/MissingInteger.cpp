// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h> 
using namespace std; 


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int i;
    int index = 0;
    
    sort(A.begin(), A.end());
    
    for (i = 0; i < A.size(); i++)
    {
        if (A.at(i) > 0)
        {
            index = i;
            break;
        }
    }
    
    if (A.at(index) != 1)
    {
        return 1;
    }
    else
    {
        for (i = index; i < (A.size() - 1); i++)
        {
            if ((A.at(i + 1) - A.at(i)) > 1)
                return (A.at(i) + 1);
        }
        
        return (A.at(A.size() - 1) + 1);
    }
}

#include <vector>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int N = A.size();
    vector <int> counter(N+1);

    // count the numbers
    for (int i = 0; i < N ; i++){
        if (A[i] > 0 && A[i] <= N+1){
            // counting the number we meet
            counter[A[i]-1] = 1;
        }
        }

    for (int i = 0; i < N +1 ; i++){
        if (!(counter[i])) return i+1;
    }

    // compiler shouldnt reach here
    return -1;
}