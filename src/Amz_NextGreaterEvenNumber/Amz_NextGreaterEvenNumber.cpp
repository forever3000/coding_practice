#include <iostream> 
using namespace std;

template <typename T>
void Swap (T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

string FindNextGreaterNumber (string str) {
    string result = str;
    int N = str.size();
    int swap_index_1 = -1;
    int swap_index_2 = -1;
    int min = INT_MAX;

    if (N <= 1) {
        return "";
    }

    for (int i = N - 2; i > 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (str[j] > str[i]) {
                int gap = str[j] - str[i];
                if (gap < min) {
                    min = gap;
                    swap_index_1 = i;
                    swap_index_2 = j;
                }
            }
        }
        if (swap_index_1 >= 0 && swap_index_2 >= 0) {
            break;
        }
    }

    if (swap_index_1 >= 0 && swap_index_2 >= 0) {
        Swap(&result[swap_index_1], &result[swap_index_2]);
        if (swap_index_1 >= 0) {
            sort(&result[swap_index_1 + 1], &result[N]);
        }
        return result;
    } else {
        return "";
    }
}

string FindNextGreaterEvenNumber (string str) {
    string result = str;
    bool even = false;

    while (even == false) {
        result = FindNextGreaterNumber(result);
        if (result.size() <= 1) {
            break;
        } else if ((result[result.size() - 1] - 0x50) % 2 == 0) {
            even = true;
        }
        
    } 
    if (even == true)
        return result;
    else
        return "";
}

int main (void) {
    string input = "76632810777910";
    //string input = "111";
    
    cout << FindNextGreaterEvenNumber(input) << endl;

    return 0;
}
