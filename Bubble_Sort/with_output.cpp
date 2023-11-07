#include <iostream>
#include <vector>
using namespace std;

int optimizedBubbleSort(vector<int>& array) {
    int iterations = 0;
    bool swapped;
    for (int i = 0; i < array.size() - 1; i++) {
        swapped = false;
        cout << "Pass " << i + 1 << ":" << endl;
        for (int j = 0; j < array.size() - i - 1; j++) {
            iterations++;
            cout << "Comparing elements " << array[j] << " and " << array[j + 1] << endl;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
                cout << "Swapping elements: " << array[j] << " and " << array[j + 1] << endl;
            }
        }
        if (!swapped) {
            cout << "No swaps made. Array already sorted." << endl;
            break;
        }
    }
    return iterations;
}

int main() {
    vector<int> array = {1, 5, 3, 8, 6, 2, 7, 4, 9};

    int iterations = optimizedBubbleSort(array);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of iterations: " << iterations << endl;

    return 0;
}


/*
Pass 1:
Comparing elements 1 and 5
Comparing elements 5 and 3
Swapping elements: 3 and 5
Comparing elements 5 and 8
Comparing elements 8 and 6
Swapping elements: 6 and 8
Comparing elements 8 and 2
Swapping elements: 2 and 8
Comparing elements 8 and 7
Swapping elements: 7 and 8
Comparing elements 8 and 4
Swapping elements: 4 and 8
Comparing elements 8 and 9
Pass 2:
Comparing elements 1 and 3
Comparing elements 3 and 5
Comparing elements 5 and 6
Comparing elements 6 and 2
Swapping elements: 2 and 6
Comparing elements 6 and 7
Comparing elements 7 and 4
Swapping elements: 4 and 7
Comparing elements 7 and 8
Pass 3:
Comparing elements 1 and 3
Comparing elements 3 and 5
Comparing elements 5 and 2
Swapping elements: 2 and 5
Comparing elements 5 and 6
Comparing elements 6 and 4
Swapping elements: 4 and 6
Comparing elements 6 and 7
Pass 4:
Comparing elements 1 and 3
Comparing elements 3 and 2
Swapping elements: 2 and 3
Comparing elements 3 and 5Comparing elements 5 and 4
Swapping elements: 4 and 5
Comparing elements 5 and 6
Pass 5:
Comparing elements 1 and 2
Comparing elements 2 and 3
Comparing elements 3 and 4
Comparing elements 4 and 5
No swaps made. Array already sorted.
Sorted array: 1 2 3 4 5 6 7 8 9 
Number of iterations: 30
*/
