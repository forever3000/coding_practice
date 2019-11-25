// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

typedef struct fish {
    int direction;
    int size;
} fish_t;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    vector<fish_t> result;
    fish_t curr_fish;
    int survivals = 0;
    
    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (B.at(i) == 0)
        {
            if (result.size() == 0)
            {
                survivals ++;                
            }
            else
            {
                while (result.size() != 0)
                {
                    if (result.at(result.size()-1).size < A.at(i))
                    {
                        result.pop_back();
                    }
                    else
                        break;
                }
                
                if (result.size() == 0)
                {
                    survivals ++;                    
                }
            }
        }
        else
        {
            curr_fish.direction = B.at(i);
            curr_fish.size = A.at(i);
            result.push_back(curr_fish);
        }
    }
    
    return (survivals + result.size());
}