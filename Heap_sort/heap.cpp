#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void heapify(vector<int>& nums, int heap_size, int root_index) {
    // Assume the index of the largest element is the root index
    int largest = root_index;
    int left_child = (2 * root_index) + 1;
    int right_child = (2 * root_index) + 2;

    if (left_child < heap_size && nums[left_child] > nums[largest]) {
        largest = left_child;
    }

    if (right_child < heap_size && nums[right_child] > nums[largest]) {
        largest = right_child;
    }

    if (largest != root_index) {
        cout << "Swapping " << nums[root_index] << " and " << nums[largest] << endl;
        swap(nums[root_index], nums[largest]);
        // Heapify the new root element to ensure it's the largest
        heapify(nums, heap_size, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(nums, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main() {
    // Input array
    vector<int> randomList = {35, 12, 43, 8, 51};

    // Output
    cout << "Input Array:" << endl;
    printArray(randomList);
    cout << "\nApplying Heap Sort...\n";

    // Call the heapSort function
    heapSort(randomList);

    // Print the sorted array
    cout << "\nSorted Array:" << endl;
    printArray(randomList);

    return 0;
}


/*
Output:
Input Array:
35 12 43 8 51 

Applying Heap Sort...
Swapping 12 and 51
Swapping 35 and 51
Swapping 12 and 43
Swapping 8 and 35

Sorted Array:
8 12 35 43 51 
*/
