#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int left, int right) {
  
  while (left <= right) {
    int middle = left + (right - left) / 2;

    cout << "Current range: [" << array[left] << ", ..., " << array[right] << "]" << endl;
    cout << "Checking element at index " << middle << " which is " << array[middle] << endl;

    if (array[middle] == x)
      return middle;

    if (array[middle] < x) {
      left = middle + 1;
      cout << "Element " << x << " is in the right half." << endl;
    } else {
      right = middle - 1;
      cout << "Element " << x << " is in the left half." << endl;
    }
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);

  cout << "Searching for element " << x << " in the array: ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  int result = binarySearch(array, x, 0, n - 1);

  if (result == -1)
    cout << "Element " << x << " not found." << endl;
  else
    cout << "Element " << x << " found at index " << result << "." << endl;

  return 0;
}
