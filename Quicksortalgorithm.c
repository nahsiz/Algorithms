#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Function to partition the array
int partition(int arr[], int low, int high) {
int pivot = arr[low];  // First element as pivot
int i = low, j = high;
while (i < j) {
// Find element greater than pivot
do  { i++; }
while (arr[i] <= pivot && i <= high);
// Find element less than or equal to pivot
do  { j--; }
while (arr[j] > pivot && j >= low);
// Swap if needed
if (i < j) swap(&arr[i], &arr[j]);
}
// Place pivot in correct position
swap(&arr[low], &arr[j]);
return j;
}
// QuickSort function
void quickSort(int arr[], int low, int high) {
if (low < high) {
// Get partition index
int j = partition(arr, low, high + 1);
// Sort left part
quickSort(arr, low, j - 1);
// Sort right part
quickSort(arr, j + 1, high);
}
}
// Function to print array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}
//Main Function
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
// Get array input
printf("Enter %d integers:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printf("Original array: ");
printArray(arr, n);
quickSort(arr, 0, n - 1);
printf("Sorted array: ");
printArray(arr, n);
return 0;
}
