#include <iostream>
#include <set>
using namespace std;

int FindTheLongestSubString (string s) {
    int N = s.size();
    int start, end = 0;
    int max_length = 1;
    int hash_table[128] = {0};

    for (int i = 0; i < N; i++) {
        if (hash_table[s[i]] != 0) {
            while (s[i] != s[start]) {
                hash_table[s[start]] --;
                start ++;
            }
            start ++;
        } else {
            hash_table[s[i]] ++;
            end = i;
            max_length = max (end - start + 1, max_length);
        }
    }

    return max_length;
}

int main (void) {
    string s = "qwertyurtasdfghj";
    cout << FindTheLongestSubString(s) << endl;
    return 0;
}
