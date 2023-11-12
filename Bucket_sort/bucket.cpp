#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(const vector<double>& array) {
    for (double num : array) {
        cout << num << " ";
    }
    cout << endl;
}

vector<double> bucketSort(const vector<double>& array) {
    // Step 1: Create empty buckets
    vector<vector<double>> bucket(array.size());

    // Step 2: Insert elements into their respective buckets
    for (double num : array) {
        int index_b = static_cast<int>(10 * num);
        bucket[index_b].push_back(num);

        cout << "Inserting " << num << " into Bucket " << index_b << endl;
    }

    // Step 3: Sort the elements of each bucket
    for (int i = 0; i < bucket.size(); ++i) {
        sort(bucket[i].begin(), bucket[i].end());

        cout << "Sorting Bucket " << i << ": ";
        printArray(bucket[i]);
    }

    // Step 4: Get the sorted elements
    vector<double> sortedArray;
    for (const auto& b : bucket) {
        sortedArray.insert(sortedArray.end(), b.begin(), b.end());
    }

    return sortedArray;
}

int main() {
    // Input array
    vector<double> array = {.42, .32, .33, .52, .37, .47, .51};

    // Output
    cout << "Input Array:" << endl;
    printArray(array);
    cout << "\nApplying Bucket Sort...\n";

    // Call the bucketSort function
    vector<double> sortedArray = bucketSort(array);

    // Print the sorted array
    cout << "\nSorted Array:" << endl;
    printArray(sortedArray);

    return 0;
}


/*Output:
Input Array:
0.42 0.32 0.33 0.52 0.37 0.47 0.51 

Applying Bucket Sort...
Inserting 0.42 into Bucket 4
Inserting 0.32 into Bucket 3
Inserting 0.33 into Bucket 3
Inserting 0.52 into Bucket 5
Inserting 0.37 into Bucket 3
Inserting 0.47 into Bucket 4
Inserting 0.51 into Bucket 5
Sorting Bucket 0: 
Sorting Bucket 1: 
Sorting Bucket 2: 
Sorting Bucket 3: 0.32 0.33 0.37 
Sorting Bucket 4: 0.42 0.47 
Sorting Bucket 5: 0.51 0.52 
Sorting Bucket 6: 

Sorted Array:
0.32 0.33 0.37 0.42 0.47 0.51 0.52 
  */
