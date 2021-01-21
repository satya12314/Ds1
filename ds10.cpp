
// Heap sort

// It is similar to selection sort algo where we find
//  the max element and place the max element at the end.

#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
 int largest=i;
 int l=2*i+1;
 int m=2*i+2;
 if(l<n && arr[l]>arr[largest])
 {
     largest=l;
 }
 if(m<n && arr[m]>arr[largest])
 {
     largest=m;
 }
 if(largest!=i)
 {
     swap(arr[i],arr[largest]);
     heapify(arr,n,largest);
 }
}
    void heapSort(int arr[], int n)
{
    // Build heap (rearrange array
    for (int i = 0; i <n; i++){
        heapify(arr, n, i);}

    for(int i = n-1 ; i > 0 ; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}