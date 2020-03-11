// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int i =0;
    unsigned int j =0;
    vector<int> result(P.size(), 999);
    int occurrences[S.size()][4] = {0};
        
    for (i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A')
            occurrences[i][0] = 1;
        else if (S[i] == 'C')
            occurrences[i][1] = 1;
        else if (S[i] == 'G')
            occurrences[i][2] = 1;
        else if (S[i] == 'T')
            occurrences[i][3] = 1;
    }
    
    for (i = 1; i < S.size(); i++)
    {
        for (j = 0; j < 4; j++)
        {
            occurrences[i][j] += occurrences[i - 1][j]; 
        }
    }
    
    for (i = 0; i < P.size(); i++)
    {
        for (j = 0; j < 4; j++)
        {
            int lower_occurrence = 0;
            int higher_occurrence = occurrences[Q.at(i)][j];
            
            if (P.at(i) > 0)
                lower_occurrence = occurrences[P.at(i) - 1][j];
                
            if (higher_occurrence - lower_occurrence > 0)
            {
                result.at(i) = j + 1;
                break;
            }
        }
    }
    
    return result;
}