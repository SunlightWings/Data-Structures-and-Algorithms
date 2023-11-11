#include <iostream>
#include <vector>
#include <algorithm> // For swap
#include <random>
using namespace std;

int iterations = 0;

void selectionSort(vector<int>& array) {
    for (int i = 0; i < array.size(); ++i) {
        int minimum_index = i;

        cout << "Iteration " << i + 1 << ":" << endl;

        for (int j = i + 1; j < array.size(); ++j) {
            iterations++;
            cout << "Comparing elements " << array[minimum_index] << " and " << array[j] << ": ";
            if (array[minimum_index] > array[j]) {
                minimum_index = j;
                cout << "Minimum updated to " << array[minimum_index] << endl;
            } else {
                cout << "No change" << endl;
            }
        }

        if (minimum_index != i) {
            swap(array[i], array[minimum_index]);
            cout << "Swapping elements " << array[i] << " and " << array[minimum_index] << ": ";
            cout << array[i] << " is moved to the left of " << array[minimum_index] << endl;
        } else {
            cout << "No swap needed\n";
        }

        cout << "Array after iteration " << i + 1 << ": ";
        for (int num : array) {
            cout << num << " ";
        }
        cout << "\n\n";
    }
}

int main() {
    vector<int> array;
    for (int i = 0; i < 20; ++i) {
        array.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(array.begin(), array.end(), g);

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << "\n\n";

    selectionSort(array);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << "\n\n";

    //cout << "Number of iterations: " << iterations << endl;

    return 0;
}

/*
Output:
Original array: 10 19 17 2 4 0 15 3 18 12 6 13 1 8 11 9 5 14 16 7 

Iteration 1:
Comparing elements 10 and 19: No change
Comparing elements 10 and 17: No change
Comparing elements 10 and 2: Minimum updated to 2
Comparing elements 2 and 4: No change
Comparing elements 2 and 0: Minimum updated to 0
Comparing elements 0 and 15: No change
Comparing elements 0 and 3: No change
Comparing elements 0 and 18: No change
Comparing elements 0 and 12: No change
Comparing elements 0 and 6: No change
Comparing elements 0 and 13: No change
Comparing elements 0 and 1: No change
Comparing elements 0 and 8: No change
Comparing elements 0 and 11: No change
Comparing elements 0 and 9: No change
Comparing elements 0 and 5: No change
Comparing elements 0 and 14: No change
Comparing elements 0 and 16: No change
Comparing elements 0 and 7: No change
Swapping elements 0 and 10: 0 is moved to the left of 10
Array after iteration 1: 0 19 17 2 4 10 15 3 18 12 6 13 1 8 11 9 5 14 16 7 

Iteration 2:
Comparing elements 19 and 17: Minimum updated to 17
Comparing elements 17 and 2: Minimum updated to 2
Comparing elements 2 and 4: No change
Comparing elements 2 and 10: No change
Comparing elements 2 and 15: No change
Comparing elements 2 and 3: No change
Comparing elements 2 and 18: No change
Comparing elements 2 and 12: No change
Comparing elements 2 and 6: No change
Comparing elements 2 and 13: No change
Comparing elements 2 and 1: Minimum updated to 1
Comparing elements 1 and 8: No change
Comparing elements 1 and 11: No change
Comparing elements 1 and 9: No change
Comparing elements 1 and 5: No change
Comparing elements 1 and 14: No change
Comparing elements 1 and 16: No change
Comparing elements 1 and 7: No change
Swapping elements 1 and 19: 1 is moved to the left of 19
Array after iteration 2: 0 1 17 2 4 10 15 3 18 12 6 13 19 8 11 9 5 14 16 7 

Iteration 3:
Comparing elements 17 and 2: Minimum updated to 2
Comparing elements 2 and 4: No change
Comparing elements 2 and 10: No change
Comparing elements 2 and 15: No change
Comparing elements 2 and 3: No change
Comparing elements 2 and 18: No change
Comparing elements 2 and 12: No change
Comparing elements 2 and 6: No change
Comparing elements 2 and 13: No change
Comparing elements 2 and 19: No change
Comparing elements 2 and 8: No change
Comparing elements 2 and 11: No change
Comparing elements 2 and 9: No change
Comparing elements 2 and 5: No change
Comparing elements 2 and 14: No change
Comparing elements 2 and 16: No change
Comparing elements 2 and 7: No change
Swapping elements 2 and 17: 2 is moved to the left of 17
Array after iteration 3: 0 1 2 17 4 10 15 3 18 12 6 13 19 8 11 9 5 14 16 7 

Iteration 4:
Comparing elements 17 and 4: Minimum updated to 4
Comparing elements 4 and 10: No change
Comparing elements 4 and 15: No change
Comparing elements 4 and 3: Minimum updated to 3
Comparing elements 3 and 18: No change
Comparing elements 3 and 12: No change
Comparing elements 3 and 6: No change
Comparing elements 3 and 13: No change
Comparing elements 3 and 19: No change
Comparing elements 3 and 8: No change
Comparing elements 3 and 11: No change
Comparing elements 3 and 9: No change
Comparing elements 3 and 5: No change
Comparing elements 3 and 14: No change
Comparing elements 3 and 16: No change
Comparing elements 3 and 7: No change
Swapping elements 3 and 17: 3 is moved to the left of 17
Array after iteration 4: 0 1 2 3 4 10 15 17 18 12 6 13 19 8 11 9 5 14 16 7 

Iteration 5:
Comparing elements 4 and 10: No change
Comparing elements 4 and 15: No change
Comparing elements 4 and 17: No change
Comparing elements 4 and 18: No change
Comparing elements 4 and 12: No change
Comparing elements 4 and 6: No change
Comparing elements 4 and 13: No change
Comparing elements 4 and 19: No change
Comparing elements 4 and 8: No change
Comparing elements 4 and 11: No change
Comparing elements 4 and 9: No change
Comparing elements 4 and 5: No change
Comparing elements 4 and 14: No change
Comparing elements 4 and 16: No change
Comparing elements 4 and 7: No change
No swap needed
Array after iteration 5: 0 1 2 3 4 10 15 17 18 12 6 13 19 8 11 9 5 14 16 7 

Iteration 6:
Comparing elements 10 and 15: No change
Comparing elements 10 and 17: No change
Comparing elements 10 and 18: No change
Comparing elements 10 and 12: No change
Comparing elements 10 and 6: Minimum updated to 6
Comparing elements 6 and 13: No change
Comparing elements 6 and 19: No change
Comparing elements 6 and 8: No change
Comparing elements 6 and 11: No change
Comparing elements 6 and 9: No change
Comparing elements 6 and 5: Minimum updated to 5
Comparing elements 5 and 14: No change
Comparing elements 5 and 16: No change
Comparing elements 5 and 7: No change
Swapping elements 5 and 10: 5 is moved to the left of 10
Array after iteration 6: 0 1 2 3 4 5 15 17 18 12 6 13 19 8 11 9 10 14 16 7 

Iteration 7:
Comparing elements 15 and 17: No change
Comparing elements 15 and 18: No change
Comparing elements 15 and 12: Minimum updated to 12
Comparing elements 12 and 6: Minimum updated to 6
Comparing elements 6 and 13: No change
Comparing elements 6 and 19: No change
Comparing elements 6 and 8: No change
Comparing elements 6 and 11: No change
Comparing elements 6 and 9: No change
Comparing elements 6 and 10: No change
Comparing elements 6 and 14: No change
Comparing elements 6 and 16: No change
Comparing elements 6 and 7: No change
Swapping elements 6 and 15: 6 is moved to the left of 15
Array after iteration 7: 0 1 2 3 4 5 6 17 18 12 15 13 19 8 11 9 10 14 16 7 

Iteration 8:
Comparing elements 17 and 18: No change
Comparing elements 17 and 12: Minimum updated to 12
Comparing elements 12 and 15: No change
Comparing elements 12 and 13: No change
Comparing elements 12 and 19: No change
Comparing elements 12 and 8: Minimum updated to 8
Comparing elements 8 and 11: No change
Comparing elements 8 and 9: No change
Comparing elements 8 and 10: No change
Comparing elements 8 and 14: No change
Comparing elements 8 and 16: No change
Comparing elements 8 and 7: Minimum updated to 7
Swapping elements 7 and 17: 7 is moved to the left of 17
Array after iteration 8: 0 1 2 3 4 5 6 7 18 12 15 13 19 8 11 9 10 14 16 17 

Iteration 9:
Comparing elements 18 and 12: Minimum updated to 12
Comparing elements 12 and 15: No change
Comparing elements 12 and 13: No change
Comparing elements 12 and 19: No change
Comparing elements 12 and 8: Minimum updated to 8
Comparing elements 8 and 11: No change
Comparing elements 8 and 9: No change
Comparing elements 8 and 10: No change
Comparing elements 8 and 14: No change
Comparing elements 8 and 16: No change
Comparing elements 8 and 17: No change
Swapping elements 8 and 18: 8 is moved to the left of 18
Array after iteration 9: 0 1 2 3 4 5 6 7 8 12 15 13 19 18 11 9 10 14 16 17 

Iteration 10:
Comparing elements 12 and 15: No changeComparing elements 12 and 13: No change
Comparing elements 12 and 19: No change
Comparing elements 12 and 18: No change
Comparing elements 12 and 11: Minimum updated to 11
Comparing elements 11 and 9: Minimum updated to 9
Comparing elements 9 and 10: No change
Comparing elements 9 and 14: No change
Comparing elements 9 and 16: No change
Comparing elements 9 and 17: No change
Swapping elements 9 and 12: 9 is moved to the left of 12
Array after iteration 10: 0 1 2 3 4 5 6 7 8 9 15 13 19 18 11 12 10 14 16 17 

Iteration 11:
Comparing elements 15 and 13: Minimum updated to 13
Comparing elements 13 and 19: No change
Comparing elements 13 and 18: No change
Comparing elements 13 and 11: Minimum updated to 11
Comparing elements 11 and 12: No change
Comparing elements 11 and 10: Minimum updated to 10
Comparing elements 10 and 14: No change
Comparing elements 10 and 16: No change
Comparing elements 10 and 17: No change
Swapping elements 10 and 15: 10 is moved to the left of 15
Array after iteration 11: 0 1 2 3 4 5 6 7 8 9 10 13 19 18 11 12 15 14 16 17 

Iteration 12:
Comparing elements 13 and 19: No change
Comparing elements 13 and 18: No change
Comparing elements 13 and 11: Minimum updated to 11
Comparing elements 11 and 12: No change
Comparing elements 11 and 15: No change
Comparing elements 11 and 14: No change
Comparing elements 11 and 16: No change
Comparing elements 11 and 17: No change
Swapping elements 11 and 13: 11 is moved to the left of 13
Array after iteration 12: 0 1 2 3 4 5 6 7 8 9 10 11 19 18 13 12 15 14 16 17 

Iteration 13:
Comparing elements 19 and 18: Minimum updated to 18
Comparing elements 18 and 13: Minimum updated to 13
Comparing elements 13 and 12: Minimum updated to 12
Comparing elements 12 and 15: No change
Comparing elements 12 and 14: No change
Comparing elements 12 and 16: No change
Comparing elements 12 and 17: No change
Swapping elements 12 and 19: 12 is moved to the left of 19
Array after iteration 13: 0 1 2 3 4 5 6 7 8 9 10 11 12 18 13 19 15 14 16 17 

Iteration 14:
Comparing elements 18 and 13: Minimum updated to 13
Comparing elements 13 and 19: No change
Comparing elements 13 and 15: No change
Comparing elements 13 and 14: No change
Comparing elements 13 and 16: No change
Comparing elements 13 and 17: No change
Swapping elements 13 and 18: 13 is moved to the left of 18
Array after iteration 14: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 18 19 15 14 16 17 

Iteration 15:
Comparing elements 18 and 19: No change
Comparing elements 18 and 15: Minimum updated to 15
Comparing elements 15 and 14: Minimum updated to 14
Comparing elements 14 and 16: No change
Comparing elements 14 and 17: No change
Swapping elements 14 and 18: 14 is moved to the left of 18
Array after iteration 15: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 19 15 18 16 17 

Iteration 16:
Comparing elements 19 and 15: Minimum updated to 15
Comparing elements 15 and 18: No change
Comparing elements 15 and 16: No change
Comparing elements 15 and 17: No change
Swapping elements 15 and 19: 15 is moved to the left of 19
Array after iteration 16: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 19 18 16 17 

Iteration 17:
Comparing elements 19 and 18: Minimum updated to 18
Comparing elements 18 and 16: Minimum updated to 16
Comparing elements 16 and 17: No change
Swapping elements 16 and 19: 16 is moved to the left of 19
Array after iteration 17: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 18 19 17 Iteration 18:
Comparing elements 18 and 19: No change
Comparing elements 18 and 17: Minimum updated to 17
Swapping elements 17 and 18: 17 is moved to the left of 18
Array after iteration 18: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 19 18 

Iteration 19:
Comparing elements 19 and 18: Minimum updated to 18
Swapping elements 18 and 19: 18 is moved to the left of 19
Array after iteration 19: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 

Iteration 20:
No swap needed
Array after iteration 20: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 

Sorted array: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
*/
