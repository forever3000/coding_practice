#include <iostream> 
#include <vector>

using namespace std;

int TrappingRainWater (vector<int> a) {
    int N = a.size();
    vector<int> height_from_left;
    vector<int> height_from_right;
    int max_left = 0;
    int max_right = 0;
    int total_water = 0;

    for (int i = 0; i < N; i++) {
        max_left = max (max_left, a.at(i));
        height_from_left.push_back(max_left);
    }

    for (int i = N-1; i >=0; i--) {
        max_right = max(max_right, a.at(i));
        height_from_right.push_back(max_right);
    }

    for (int i = 0; i < N; i++) {
        total_water += min(height_from_left.at(i), height_from_right.at(i)) - a.at(i);
    }

    return total_water;
}

int main (void) {
    vector<int> a = {3,0,0,2,0,4};
    
    cout << TrappingRainWater(a) << endl;

    return 0;
}
