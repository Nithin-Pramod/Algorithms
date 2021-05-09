#include <iostream>
using namespace std;

void sorted(int arr[] , int n)
{
    int key,j;
    for(int i =1 ; i<n ; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]={33,22,1,344,2,1,211,4};
    int n=sizeof(arr)/sizeof(int);
    sorted(arr,n);
}
