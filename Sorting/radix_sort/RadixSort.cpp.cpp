/*
RADIX SORT ALGORITHM : TIME COMPLEXITY : O(nlog(n))
*/

#include <iostream>
using namespace std;

// function to get the max value from array elements
int getMax(int arr[], int n) {
  int mx = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;
}

// print function to print the array
void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

// countSort Implementing
void countSort(int arr[], int n, int exp) {
  int output[n]; // output array
  int i, count[10] = {0};

  // Storing the count of occurrences in count[]  array
  for (i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  // Change count[i] so that count[i]
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // output array building
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // array now contains sorted numbers according to current digit
  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

// Raix sort function
void radix_sort(int arr[], int n) {
  // Finding maximum number to know number of digits
  int m = getMax(arr, n);

  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(arr, n, exp);
}

// main function
int main() {

  // input array to sort
  int arr[] = {2, 3, 44, 88, 986, 8654, 344, 911};
  // size of array
  int n = sizeof(arr) / sizeof(arr[0]);

  // calling radix sort function
  radix_sort(arr, n);

  // printing the sorted array
  print(arr, n);
}
