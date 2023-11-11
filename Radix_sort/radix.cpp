#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << "\n\n";
}

int getMax(const vector<int>& array) {
    return *max_element(array.begin(), array.end());
}

void countSort(vector<int>& array, int exp) {
    const int base = 10;
    vector<int> output(array.size());
    vector<int> count(base, 0);

    for (int num : array) {
        int digit = (num / exp) % base;
        count[digit]++;
    }

    for (int i = 1; i < base; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; --i) {
        int digit = (array[i] / exp) % base;
        output[count[digit] - 1] = array[i];
        count[digit]--;

        cout << "Element " << array[i] << " with digit " << digit << " moved to position "
             << count[digit] << endl;
    }

    array = output;
}

void radixSort(vector<int>& array) {
    int maxNum = getMax(array);
    int maxDigits = static_cast<int>(log10(maxNum) + 1);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        cout << "Pass with digit position " << exp << ":\n";
        countSort(array, exp);
        cout << "Array after pass: ";
        printArray(array);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> array;
    for (int i = 0; i < 10; ++i) {
        array.push_back(rand() % 100);
    }

    cout << "Original array: ";
    printArray(array);

    radixSort(array);

    cout << "Sorted array: ";
    printArray(array);

    return 0;
}


/*
Output:
Original array: 64 81 61 32 47 31 42 10 86 48 

Pass with digit position 1:
Element 48 with digit 8 moved to position 9
Element 86 with digit 6 moved to position 7
Element 10 with digit 0 moved to position 0
Element 42 with digit 2 moved to position 5
Element 31 with digit 1 moved to position 3
Element 47 with digit 7 moved to position 8
Element 32 with digit 2 moved to position 4
Element 61 with digit 1 moved to position 2
Element 81 with digit 1 moved to position 1
Element 64 with digit 4 moved to position 6
Array after pass: 10 81 61 31 32 42 64 86 47 48 

Pass with digit position 10:
Element 48 with digit 4 moved to position 5
Element 47 with digit 4 moved to position 4
Element 86 with digit 8 moved to position 9
Element 64 with digit 6 moved to position 7
Element 42 with digit 4 moved to position 3
Element 32 with digit 3 moved to position 2
Element 31 with digit 3 moved to position 1
Element 61 with digit 6 moved to position 6
Element 81 with digit 8 moved to position 8
Element 10 with digit 1 moved to position 0
Array after pass: 10 31 32 42 47 48 61 64 81 86 

Sorted array: 10 31 32 42 47 48 61 64 81 86 
*/
