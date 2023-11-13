#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i < left.size() && (j == right.size() || left[i] <= right[j])) {
            result.push_back(left[i]);
            cout << "Appending " << left[i] << " to the result" << endl;
            i++;
        } else {
            result.push_back(right[j]);
            cout << "Appending " << right[j] << " to the result" << endl;
            j++;
        }
    }

    return result;
}

vector<int> mergeSort(const vector<int>& array) {
    if (array.size() < 2) {
        return array;
    }

    int mid = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + mid);
    vector<int> right(array.begin() + mid, array.end());

    cout << "Splitting: ";
    printArray(array);

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    // Input array
    vector<int> array;
    for (int i = 1; i <= 19; ++i) {
        array.push_back(i);
    }

    // Shuffle the array
    random_device rd;
    mt19937 g(rd());
    shuffle(array.begin(), array.end(), g);

    // Output
    cout << "Input Array:" << endl;
    printArray(array);
    cout << "\nApplying Merge Sort...\n";

    // Call the mergeSort function
    vector<int> sortedArray = mergeSort(array);

    // Print the sorted array
    cout << "\nSorted Array:" << endl;
    printArray(sortedArray);

    return 0;
}


/*Output:
/tmp/t4tGbucLWp.o
Input Array:
14 16 7 17 11 13 12 19 15 6 5 4 18 1 9 10 2 8 3 

Applying Merge Sort...
Splitting: 14 16 7 17 11 13 12 19 15 6 5 4 18 1 9 10 2 8 3 
Splitting: 14 16 7 17 11 13 12 19 15 
Splitting: 14 16 7 17 
Splitting: 14 16 
Appending 14 to the result
Appending 16 to the result
Splitting: 7 17 
Appending 7 to the result
Appending 17 to the result
Appending 7 to the result
Appending 14 to the result
Appending 16 to the result
Appending 17 to the result
Splitting: 11 13 12 19 15 
Splitting: 11 13 
Appending 11 to the result
Appending 13 to the result
Splitting: 12 19 15 
Splitting: 19 15 
Appending 15 to the result
Appending 19 to the result
Appending 12 to the result
Appending 15 to the result
Appending 19 to the result
Appending 11 to the result
Appending 12 to the result
Appending 13 to the result
Appending 15 to the result
Appending 19 to the result
Appending 7 to the result
Appending 11 to the result
Appending 12 to the result
Appending 13 to the result
Appending 14 to the result
Appending 15 to the result
Appending 16 to the result
Appending 17 to the result
Appending 19 to the result
Splitting: 6 5 4 18 1 9 10 2 8 3 
Splitting: 6 5 4 18 1 
Splitting: 6 5 
Appending 5 to the result
Appending 6 to the result
Splitting: 4 18 1 
Splitting: 18 1 
Appending 1 to the result
Appending 18 to the result
Appending 1 to the result
Appending 4 to the result
Appending 18 to the result
Appending 1 to the result
Appending 4 to the result
Appending 5 to the result
Appending 6 to the result
Appending 18 to the result
Splitting: 9 10 2 8 3 
Splitting: 9 10 
Appending 9 to the result
Appending 10 to the result
Splitting: 2 8 3 
Splitting: 8 3 
Appending 3 to the result
Appending 8 to the result
Appending 2 to the result
Appending 3 to the result
Appending 8 to the result
Appending 2 to the result
Appending 3 to the result
Appending 8 to the result
Appending 9 to the result
Appending 10 to the result
Appending 1 to the result
Appending 2 to the result
Appending 3 to the result
Appending 4 to the result
Appending 5 to the result
Appending 6 to the result
Appending 8 to the result
Appending 9 to the result
Appending 10 to the result
Appending 18 to the result
Appending 1 to the result
Appending 2 to the result
Appending 3 to the result
Appending 4 to the result
Appending 5 to the result
Appending 6 to the result
Appending 7 to the result
Appending 8 to the result
Appending 9 to the result
Appending 10 to the result
Appending 11 to the result
Appending 12 to the result
Appending 13 to the result
Appending 14 to the result
Appending 15 to the result
Appending 16 to the result
Appending 17 to the result
Appending 18 to the result
Appending 19 to the result

Sorted Array:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
*/
