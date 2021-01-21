
// Heap

#include <bits/stdc++.h>
using namespace std;

int maxHeap(int *arr, int n, int value)
{
    n = n + 1;
    int parent;
    arr[n] = value;
    int i = n;
    while (i > 1)
    {
        parent = i / 2;
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            i = parent;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
void heapify(int *arr, int n, int i)
{

    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
    
}

void deleteRoot(int arr[], int& n) 
{ 
    // Get the last element 
    int lastElement = arr[n - 1]; 
  
    // Replace root with first element 
    arr[0] = lastElement; 
  
    // Decrease size of heap by 1 
    n = n - 1; 
  
    // heapify the root node 
    heapify(arr, n, 0); 
} 

int main()
{
    
    int arr[5] = {10, 5, 3, 2, 4};
    int n = 5;
    
    deleteRoot(arr, n);

    
    for (int i = 0; i < n; ++i)
    {

        cout << arr[i] << " ";
    }
}
