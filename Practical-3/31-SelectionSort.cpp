#include<iostream>
using namespace std;

void SelectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
                mini=j;
        }
        if(mini!=i)
        {
            int temp=a[i];
            a[i]=a[mini];
            a[mini]=temp;
        }
    }
    cout << "Sorted using Selection Sort: ";
    for(int i=0;i<n;i++)
        cout<<a[i];
}


int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin>>n;

    int a[n];

    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    SelectionSort(a,n);
}

