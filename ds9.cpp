//Selection sort

#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void selection(int arr[], int n)  
{  
    int i, j, min;  
  
    
    for (i = 0; i < n-1; i++)  
    {  
        
        min = i;  
        for (j = i+1; j < n; j++)  
        {
        if (arr[j] < arr[min])  
            min = j;  
        }
        
        swap(&arr[min], &arr[i]);  
    }  
}  

int main()
{
int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selection(arr, n);  
    cout << "Sorted array: \n"; 
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
}