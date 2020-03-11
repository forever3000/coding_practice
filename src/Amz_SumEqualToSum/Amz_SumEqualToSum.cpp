// A binary search based program to find the 
// only missing number in a sorted array of 
// distinct elements within limited range. 
#include <iostream>
#include <vector>
#include <set>

using namespace std; 

bool CheckSumEqualToSum (vector<int> a) {
    int N = a.size();
    set<int> hash_table;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int sum = a.at(i) + a.at(j);
            if (hash_table.find(sum) != hash_table.end()) {
                cout << "Sum: " << sum << endl;
                return true;
            } else {
                hash_table.insert(sum);
            }
        }
    }
    return false;
}

int main (void) {
    vector<int> a{65, 30, 7, 90, 1, 9, 8};
    vector<int> b{3, 4, 7, 1, 2, 9, 8};
    if (CheckSumEqualToSum(a)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    if (CheckSumEqualToSum(b)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
