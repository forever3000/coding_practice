#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a[] = {0, 1, 1, 1, 1, 1, 4 ,5};
    int N = sizeof(a) /sizeof(int);
    int pre_of_consecutive = 0;
    int curr_of_consecutive = 0;
    bool result = true;

    for (int i = 0; i < N; i++) {
        if (a[i] == 1) {
            pre_of_consecutive ++;
            curr_of_consecutive ++;
            if (pre_of_consecutive != curr_of_consecutive) {
                result = false;
                break;
            }
        } else {
            curr_of_consecutive = 0;
        }
    }

    cout << result << endl;

    return 0;
}
