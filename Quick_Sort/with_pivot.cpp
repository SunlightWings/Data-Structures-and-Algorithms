#include <iostream>
#include <vector>
#include <algorithm> // Added for random_shuffle
using namespace std;

int partition(vector<int>& array, int low, int high) {
    int i = low - 1;
    int pivot = array[high];

    for (int j = low; j <= high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        cout << "Pivot element: " << array[pivot] << endl;

        cout << "Left sub-array: ";
        for (int i = low; i < pivot; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        cout << "Right sub-array: ";
        for (int i = pivot + 1; i <= high; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

int main() {
    vector<int> array;
    for (int i = 1; i <= 19; i++) {
        array.push_back(i);
    }

    random_shuffle(array.begin(), array.end()); // Shuffling the array

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(array, 0, array.size() - 1);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



/* Output:

Original array: 5 11 12 16 15 17 18 2 7 10 4 8 9 3 1 13 6 19 14 
Pivot element: 14
Left sub-array: 5 11 12 2 7 10 4 8 9 3 1 13 6 
Right sub-array: 18 16 15 19 17 
Pivot element: 6
Left sub-array: 5 2 4 3 1 
Right sub-array: 12 8 9 11 7 13 10 
Pivot element: 1
Left sub-array: 
Right sub-array: 2 4 3 5 
Pivot element: 5
Left sub-array: 2 4 3 
Right sub-array: 
Pivot element: 3
Left sub-array: 2 
Right sub-array: 4 
Pivot element: 10
Left sub-array: 8 9 7 
Right sub-array: 12 13 11 
Pivot element: 7
Left sub-array: 
Right sub-array: 9 8 
Pivot element: 8
Left sub-array: 
Right sub-array: 9 
Pivot element: 11
Left sub-array: 
Right sub-array: 13 12 
Pivot element: 12
Left sub-array: 
Right sub-array: 13 
Pivot element: 17
Left sub-array: 16 15 
Right sub-array: 19 18 
Pivot element: 15
Left sub-array: 
Right sub-array: 16 
Pivot element: 18
Left sub-array: 
Right sub-array: 19 
Sorted array: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
  */
