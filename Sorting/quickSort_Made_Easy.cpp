#include<iostream>

using namespace std;
int partition(int arr[],int,int);

void quickSort(int arr[], int l, int h)
{
    if(l<h)
    {
    int m = partition(arr,l,h);
    quickSort(arr,l,m-1);
    quickSort(arr,m+1,h);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
   int pivot = arr[l];
   int i=l+1,j=h;
   while(i<j)
   {
       while(pivot>=arr[i])
        i++;
       while(pivot<arr[j])
        j--;
       if(i<j)
        swap(arr[i],arr[j]);
   }
   swap(arr[j],arr[l]);
   return j;
}

int main()
{
    int arr[] = {56,45,54,34,2,46,7,23,5,6,1,76,3,4,234,6,7,89};
    int high = (sizeof(arr)/sizeof(arr[0])-1);
    quickSort(arr,0,high);
    for(int i=0; i<+high; i++)
        cout << arr[i] << " ";
        return 0;
}
