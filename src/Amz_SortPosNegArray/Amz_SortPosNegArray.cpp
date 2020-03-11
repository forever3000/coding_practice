#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a[] = {-1, 6, 9, -4, -10, -9, 8, 8, 4};
    vector<int> result;
    int N = sizeof(a) /sizeof(int);
    int pos_idx = 0;
    int neg_idx = 0;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            while (pos_idx < N && a[pos_idx] < 0) {
                pos_idx++;
            }
            if (pos_idx < N) {
                result.push_back(a[pos_idx]);
                pos_idx++;
            }
        } else {
            while (neg_idx < N && a[neg_idx] > 0) {
                neg_idx++;
            }
            if (neg_idx < N) {
                result.push_back(a[neg_idx]);
                neg_idx++;
            }
        }

        cout << result.at(i) << endl;
    }
}
