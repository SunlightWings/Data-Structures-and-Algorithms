#include <iostream>
#include <vector>

void countingSort(std::vector<int>& array) {
    int size = array.size();
    std::vector<int> output(size, 0);

    // Initialize count array
    std::vector<int> count(10, 0);

    // Store the count of each element in count array
    for (int i = 0; i < size; ++i) {
        count[array[i]] += 1;
    }

    // Store the cumulative count
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array
    // Place the elements in the output array
    int i = size - 1;
    while (i >= 0) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
        i -= 1;
        std::cout << "Moving element 'value " << array[i + 1] << "' from position " << i + 1
                  << " to position " << count[array[i + 1]] << "\n";
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < size; ++i) {
        array[i] = output[i];
        std::cout << "Placing element 'value " << output[i] << "' in its final position\n";
    }
}

int main() {
    std::vector<int> data = {4, 2, 2, 8, 3, 3, 1};

    // Print the original array
    std::cout << "Original Array:\n";
    for (const auto& value : data) {
        std::cout << value << " ";
    }
    std::cout << "\n\nSorting Steps:\n";
    countingSort(data);
    std::cout << "\nSorted Array in Ascending Order:\n";
    for (const auto& value : data) {
        std::cout << value << " ";
    }

    return 0;
}

/*
Output:
Original Array:
4 2 2 8 3 3 1 

Sorting Steps:
Moving element 'value 1' from position 6 to position 0
Moving element 'value 3' from position 5 to position 4
Moving element 'value 3' from position 4 to position 3
Moving element 'value 8' from position 3 to position 6
Moving element 'value 2' from position 2 to position 2
Moving element 'value 2' from position 1 to position 1
Moving element 'value 4' from position 0 to position 5
Placing element 'value 1' in its final position
Placing element 'value 2' in its final position
Placing element 'value 2' in its final position
Placing element 'value 3' in its final position
Placing element 'value 3' in its final position
Placing element 'value 4' in its final position
Placing element 'value 8' in its final position

Sorted Array in Ascending Order:
1 2 2 3 3 4 8 
  */
