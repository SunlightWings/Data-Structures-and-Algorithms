#include <iostream>
#include <vector>
using namespace std;

int iterations = 0;

void insertionSort(vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {
        int current_value = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > current_value) {
            cout << "Comparing " << array[j] << " and " << current_value << ". ";
            cout << "Moving " << array[j] << " to the right." << endl;
            iterations++;
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current_value;
    }
}

int main() {
    vector<int> array = {14, 7, 3, 12, 9, 11, 6, 2};

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(array);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of iterations: " << iterations << endl;

    return 0;
}



/*
Output:

Original array: 14 7 3 12 9 11 6 2 
Comparing 14 and 7. Moving 14 to the right.
Comparing 14 and 3. Moving 14 to the right.
Comparing 7 and 3. Moving 7 to the right.
Comparing 14 and 12. Moving 14 to the right.
Comparing 14 and 9. Moving 14 to the right.
Comparing 12 and 9. Moving 12 to the right.
Comparing 14 and 11. Moving 14 to the right.
Comparing 12 and 11. Moving 12 to the right.
Comparing 14 and 6. Moving 14 to the right.
Comparing 12 and 6. Moving 12 to the right.
Comparing 11 and 6. Moving 11 to the right.
Comparing 9 and 6. Moving 9 to the right.
Comparing 7 and 6. Moving 7 to the right.
Comparing 14 and 2. Moving 14 to the right.
Comparing 12 and 2. Moving 12 to the right.
Comparing 11 and 2. Moving 11 to the right.
Comparing 9 and 2. Moving 9 to the right.
Comparing 7 and 2. Moving 7 to the right.
Comparing 6 and 2. Moving 6 to the right.
Comparing 3 and 2. Moving 3 to the right.
Sorted array: 2 3 6 7 9 11 12 14 
Number of iterations: 20
*/
