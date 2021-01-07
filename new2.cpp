#include <iostream>
#include <vector>
using namespace std;
using std::vector;  
using std::cout;
using std::cin;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition (vector<int>& arr, int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            swap(&arr[i], &arr[j]);  
            i++;
        }  
    }  
    swap(&arr[i], &arr[high]);  
    return i;  
}  

void quickSort(vector<int>& arr, int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

void printArray(vector<int>& arr, int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << ' ';  
    cout << endl;  
}  
  
// Driver Code 
int main()  
{  
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
