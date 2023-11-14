#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int jumpSearch(const vector<int>& arr, int x) {
    int n = arr.size();
    int step = sqrt(n);  // Define the jump step size

    int prev = 0;
    cout << "Jumping to step " << prev << "..." << endl;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Element " << x << " not found." << endl;
            return -1;
        }
        cout << "Jumping to step " << prev << "..." << endl;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) {
            cout << "Element " << x << " not found." << endl;
            return -1;
        }
        cout << "Checking element at index " << prev << "..." << endl;
    }

    if (arr[prev] == x) {
        cout << "Element " << x << " found at index " << prev << "." << endl;
        return prev;
    }

    cout << "Element " << x << " not found." << endl;
    return -1;
}

int main() {
    // Example Usage
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 17;

    int result = jumpSearch(arr, target);

    return 0;
}


/*
Output:
Jumping to step 0...
Jumping to step 3...
Jumping to step 6...
Checking element at index 7...
Checking element at index 8...
Element 17 found at index 8.
  */
