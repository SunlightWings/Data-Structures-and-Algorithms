#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << "\n\n";
}

void shellSort(vector<int>& array) {
    int n = array.size();
    int interval = n / 2;

    while (interval > 0) {
        cout << "Using interval " << interval << "\n";

        for (int i = interval; i < n; ++i) {
            int temp = array[i];
            int j = i;

            while (j >= interval && array[j - interval] > temp) {
                cout << "Moving element at position " << j - interval << " to position " << j << "\n";
                array[j] = array[j - interval];
                j -= interval;
            }

            array[j] = temp;
        }

        cout << "Array after interval " << interval << ": ";
        printArray(array);

        interval /= 2;
    }

    cout << "Final Sorted Array:\n";
    printArray(array);
}

int main() {
    vector<int> data = {9, 8, 3, 7, 5, 6, 4, 1};

    cout << "Original array: ";
    printArray(data);

    shellSort(data);

    return 0;
}


/* Output:
Original array: 9 8 3 7 5 6 4 1 

Using interval 4
Moving element at position 0 to position 4
Moving element at position 1 to position 5
Moving element at position 3 to position 7
Array after interval 4: 5 6 3 1 9 8 4 7 

Using interval 2
Moving element at position 0 to position 2
Moving element at position 1 to position 3
Moving element at position 4 to position 6
Moving element at position 2 to position 4
Moving element at position 5 to position 7
Array after interval 2: 3 1 4 6 5 7 9 8 

Using interval 1
Moving element at position 0 to position 1
Moving element at position 3 to position 4
Moving element at position 6 to position 7
Array after interval 1: 1 3 4 5 6 7 8 9 

Final Sorted Array:
1 3 4 5 6 7 8 9 
  */
