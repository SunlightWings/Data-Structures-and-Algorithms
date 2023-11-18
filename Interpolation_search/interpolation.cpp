#include <iostream>
#include <vector>

/**
 * Perform interpolation search to find element 'x' in array 'arr'.
 *
 * @param arr Vector of elements (sorted in ascending order).
 * @param lo Starting index of the subarray.
 * @param hi Ending index of the subarray.
 * @param x Element to search for.
 *
 * @return Index of the element if found, otherwise -1.
 */
int interpolationSearch(const std::vector<int>& arr, int lo, int hi, int x) {
    // Check if 'x' is within the range of the current subarray
    if (lo <= hi && arr[lo] <= x && x <= arr[hi]) {
        // Calculate the estimated position of 'x'
        int pos = lo + ((x - arr[lo]) * (hi - lo) / (arr[hi] - arr[lo]));

        // Print the search algorithm flow
        std::cout << "Checking subarray: [";
        for (int i = lo; i <= hi; ++i) {
            std::cout << arr[i];
            if (i < hi) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";

        // If 'x' is found at the estimated position
        if (arr[pos] == x) {
            std::cout << "Element " << x << " found at index " << pos << ".\n";
            return pos;
        }

        // If 'x' is likely to be on the right side
        if (arr[pos] < x) {
            std::cout << "Element " << x << " is likely on the right side of index " << pos << ".\n";
            return interpolationSearch(arr, pos + 1, hi, x);
        }

        // If 'x' is likely to be on the left side
        if (arr[pos] > x) {
            std::cout << "Element " << x << " is likely on the left side of index " << pos << ".\n";
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }

    // If 'x' is not found in the subarray
    std::cout << "Element " << x << " not found in the current subarray.\n";
    return -1;
}

int main() {
    std::vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int x = 33;

    // Print the original sorted series
    std::cout << "Sorted Series: [";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n\n";

    int index = interpolationSearch(arr, 0, arr.size() - 1, x);

    if (index != -1) {
        std::cout << "Element " << x << " found at index " << index << ".\n";
    } else {
        std::cout << "Element " << x << " not found.\n";
    }

    return 0;
}


/* Output:
Sorted Series: [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]

Checking subarray: [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]
Element 33 is likely on the right side of index 8.
Checking subarray: [23, 24, 33, 35, 42, 47]
Element 33 found at index 11.
Element 33 found at index 11.
  */
