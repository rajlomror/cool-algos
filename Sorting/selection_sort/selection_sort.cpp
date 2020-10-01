#include <iostream>

using namespace std;

void swapElement(int *m, int *n)  
{  
    int temp = *m;  
    *m = *n;  
    *n = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, minVal;  
  
    // Loop unsorted Array values 
    for (i = 0; i < n-1; i++)  
    {  
        // Find the lowest value  
        minVal = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[minVal])  
            minVal = j;  
  
        // Swap the minimum value element with the first available value at array index  
        swapElement(&arr[minVal], &arr[i]);  
    }  
}  
  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
/*
* Main Function
* select dynamic array elements
*/

int main()
{
    int Array[6];
    cout << "\nEnter any 6 Numbers for Unsorted Array : ";

    // Input
    for (int i = 0; i < 6; i++) {
        cin >> Array[i];
    }
    // int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(Array)/sizeof(Array[0]);  
    selectionSort(Array, n);  
    cout << "Sorted array: \n";  
    printArray(Array, n);  
    return 0;  
}
