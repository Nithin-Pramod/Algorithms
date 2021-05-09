#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;
vector<int> arr;
void printvector()
{
    for(int i = 0 ; i < arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
void merge(vector<int> &arr,vector<int> &l,int leftCount,vector<int> &r,int rightCount)
{
    int i,j,k;
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(l[i]  < r[j])
		{
		    arr[k] = l[i];
		    k++;
		    i++;
	    }
		else 
		{
		    arr[k] = r[j];
		    k++;
		    j++;
		    
		}
	}
	while(i < leftCount)
	{
	    arr[k] = l[i];
	    k++;
	    i++;
	}
	while(j < rightCount) 
	{
	    arr[k] = r[j];
	    k++;
	    j++;
	}
}

void mergeSort(vector<int> &arr , int n)
{
    int mid,i;
    if(n<2)return;
    mid=n/2;
    vector<int> l;
    vector<int> r;
    for(int i=0;i<mid;i++)l.push_back(arr[i]);
    for(int i=mid;i<n;i++)r.push_back(arr[i]);
    
    mergeSort(l,mid);
    mergeSort(r,n-mid);
    merge(arr,l,mid,r,n-mid);
}

int main()
{
    int value;
    cout << "Enter space seperated values :";
    string line;
    getline(cin, line); 
    istringstream iss(line); 
    while(iss >> value)
        arr.push_back(value); 
    mergeSort(arr,arr.size());  
    printvector();

    
}
