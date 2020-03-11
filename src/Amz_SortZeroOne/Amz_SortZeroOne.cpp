#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a[] = {0, 1, 1, 0, 0, 1, 0, 0, 1};
    int N = sizeof(a) /sizeof(int);
    vector<int> result(N);
    int zero_idx = 0;
    int one_idx = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] == 0) {
            result.at(zero_idx) = 0;
            zero_idx++;
        } else {
            result.at(N - 1 - one_idx) = 1;
            one_idx++;
        }

        cout << result.at(i) << endl;
    }
}
