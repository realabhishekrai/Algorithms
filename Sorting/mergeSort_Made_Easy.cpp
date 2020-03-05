#include<iostream>

using namespace std;

void merge(int arr[],int start,int mid,int end)
{
    int i=start, j = mid+1, k = 0;
    int temp[end-start+1];
    while(i<=mid && j<=end)
    {
        if(arr[i]<= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=mid)
        temp[k++] = arr[i++];

    while(j<=end)
        temp[k++] = arr[j++];

  int y =0;
    for(int z=start; z<=end; z++)
        arr[z] = temp[y++];
}

void mergeSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[] = {564,53,45,234,3,46,31,77,44,20,98,34,4,9};
    int high = sizeof(arr)/sizeof(arr[0])-1;
    mergeSort(arr,0,high);
    for(int i=0; i<=high; i++)
        cout << arr[i] << " ";
}
