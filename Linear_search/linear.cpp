#include <iostream>
#include <vector>
using namespace std;

int pos = -1;

bool search(const vector<int>& arr, int n) {
    int i = 0;

    while (i < arr.size()) {
        cout << "Checking element at index " << i << ": " << arr[i] << endl;

        if (arr[i] == n) {
            pos = i;
            cout << "Found at index " << pos << endl;
            return true;
        }

        i++;
    }

    cout << "Not Found" << endl;
    return false;
}

int main() {
    vector<int> arr = {5, 8, 4, 6, 9, 2};
    int n = 9;

    cout << "Searching for " << n << " in the array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    bool result = search(arr, n);

    cout << "Result: " << (result ? "True" : "False") << endl;

    return 0;
}


/* 
Output:
Searching for 9 in the array: 5 8 4 6 9 2 
Checking element at index 0: 5
Checking element at index 1: 8
Checking element at index 2: 4
Checking element at index 3: 6
Checking element at index 4: 9
Found at index 4
Result: True
  */
