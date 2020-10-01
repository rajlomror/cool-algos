#include <iostream>

using namespace std;

/*
* Swap fucntion
* Swap two varibale values using temp veriable
*/
void swapElement(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

/*
* Main Logic for selection sorting
*/
void selectionSort(int arr[], int n)
{
    int i, j, min;

    // Loop unsorted Array values
    for (i = 0; i < n-1; i++)
    {
        // Find the lowest value
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;  // assign smallest index to minValIndex variable

        // Swap the minimum value element with the first available value at array index
        swapElement(&arr[min], &arr[i]);
    }
}

/*
* Function to Print the sorted array
*/
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
* Main Function
* select array size
* select dynamic array elements
*/

int main()
{
    int size;
    cout << "\nEnter the size of Unsorted Array : ";
    cin >> size;
    int Array[size];
    cout << "\nEnter any " << size << " Elements for Unsorted Array: \n";

    // Input
    for (int i = 0; i < size; i++) {
        cin >> Array[i];
    }
    selectionSort(Array, size);
    cout << "Sorted array: \n";
    printArray(Array, size);
    return 0;
}
